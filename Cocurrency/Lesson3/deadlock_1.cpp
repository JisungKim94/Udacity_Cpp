#include <algorithm>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

/* 이 코드에서 mutex를 안쓰면 Data race가 생겨서 코드 output이 지 맘대로 나옴
 그래서 mutex를 사용했더니 exeption occured between lock and unlock 이
 발생하니까 코드가 freezed. 이런 형상을 deadlokc 이라고 부름*/

std::mutex mtx;
double result;

void printResult(int denom) {
  std::cout << "for denom = " << denom << ", the result is " << result
            << std::endl;
}

void divideByNumber(double num, double denom) {
  mtx.lock();
  try {
    // divide num by denom but throw an exception if division by zero is
    // attempted
    if (denom != 0) {
      result = num / denom;
      std::this_thread::sleep_for(std::chrono::milliseconds(1));
      printResult(denom);
    } else {
      throw std::invalid_argument("Exception from thread: Division by zero!");
    }
  } catch (const std::invalid_argument &e) {
    // notify the user about the exception and return
    std::cout << e.what() << std::endl;
    return;
  }
  mtx.unlock();
}

int main() {
  // create a number of threads which execute the function "divideByNumber" with
  // varying parameters
  std::vector<std::future<void>> futures;
  for (double i = -5; i <= +5; ++i) {
    futures.emplace_back(
        std::async(std::launch::async, divideByNumber, 50.0, i));
  }

  // wait for the results
  std::for_each(futures.begin(), futures.end(),
                [](std::future<void> &ftr) { ftr.wait(); });

  return 0;
}
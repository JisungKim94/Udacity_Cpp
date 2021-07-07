#include <iostream>
#include <memory>

/* 첫 번째는 공유 포인터에서 직접,
   두 번째는 첫 번째 약 포인터에서 간접적으로 생성됩니다.
   출력에서 볼 수 있듯이 두 약한 포인터 모두 참조 횟수를 증가시키지 않았습니다.
   main의 끝에서 정수 리소스에 대한 약한 포인터를 직접 만들려고하면 컴파일
   오류가 발생합니다. */

int main() {
  std::shared_ptr<int> mySharedPtr(new int);
  std::cout << "shared pointer count = " << mySharedPtr.use_count()
            << std::endl;

  std::weak_ptr<int> myWeakPtr1(mySharedPtr);
  std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
  std::cout << "shared pointer count = " << mySharedPtr.use_count()
            << std::endl;

  // std::weak_ptr<int> myWeakPtr3(new int); // COMPILE ERROR

  return 0;
}
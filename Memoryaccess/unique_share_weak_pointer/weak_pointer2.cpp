#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<int> mySharedPtr(new int);
  std::weak_ptr<int> myWeakPtr(mySharedPtr);

  mySharedPtr.reset(new int);

  /* With a weak pointer,
      even though this type does not prevent an object from being deleted,
      the validity of its resource can be checked. */
  if (myWeakPtr.expired() == true) {
    std::cout << "Weak pointer expired!" << std::endl;
  }

  return 0;
}
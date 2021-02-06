#include "ref_manager.h"

ReferenceManager::ReferenceManager() {
  numToDelete = 0;
  for (int i = 0; i < MAX_PTRS; i++) {
    pointers[i] = NULL;
  }
}

ReferenceManager::~ReferenceManager() {
  // CODE HERE
  for (int i = 0; i < pointers_size; i++)
    reassignPointer(i, NULL);
  garbageCollect();
}

void ReferenceManager::garbageCollect() {
  // CODE HERE
  for (int i = 0; i <= garbage_i; i++)
    cout << garbage[i] << endl;
  for (int i = 0; i <= garbage_i; i++)
    delete[] garbage[i];
  garbage_i = 0;
  return;
}

void ReferenceManager::reassignPointer(unsigned int ptrIndex, const char* newAddr) {
  // CODE HERE
  bool Null_checker;
  if (newAddr == NULL)
    Null_checker = true;
  else
    Null_checker = false;
  // const char *point = pointers[ptrIndex];
  refCount[pointers[ptrIndex]]--;
  if (refCount[pointers[ptrIndex]] == 0){
    // Need to add this pointer to garbage collecter array
    garbage[garbage_i] = pointers[ptrIndex];
    garbage_i++;
  }
  pointer[ptrIndex] = newAddr;
  if (refCount.find(newAddr) != refCount.end() && (!Null_checker))
    refCount[newAddr]++;
  else if (!Null_checker)
    refCount[newAddr] = 1;
  return;
}

void ReferenceManager::readString(unsigned int ptrIndex, unsigned int length) {
  // CODE HERE
  char *string = new char[length+1];
  for (int i = 0; i < length; i++)
    cin >> string[i];
  string[length] = '\0';

  reassignPointer(ptrIndex, string);
  return;
}

const char* ReferenceManager::getPtr(unsigned int ptrIndex) {
  assert(ptrIndex < MAX_PTRS);
  return pointers[ptrIndex];
}

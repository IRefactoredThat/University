#include "string.h"
#include <cstring>
#include <iostream>

String::String() : m_length(0), m_arr(nullptr) {}

String::String(const char *arr) {
  m_length = std::strlen(arr);
  m_arr = new char[m_length + 1];

  std::copy(arr, arr + m_length + 1, m_arr);
}

String::String(const String &other) {
  m_length = other.m_length;
  m_arr = new char[m_length + 1];

  std::copy(other.m_arr, other.m_arr + m_length + 1, m_arr);
}

String &String::operator=(const String &other) {
  if (this == &other)
    return *this;

  char *new_arr = new char[other.m_length + 1];

  std::copy(other.m_arr, other.m_arr + other.m_length + 1, new_arr);

  delete[] m_arr;
  m_arr = new_arr;
  m_length = other.m_length;

  return *this;
}

size_t String::getLength() const { return m_length; }

int String::getSubstringPos(const String &other) const {
  int currentMatch = 0, otherMatch = 0;
  while (currentMatch < m_length) {
    while (currentMatch < m_length && otherMatch < other.m_length &&
           m_arr[currentMatch] == other.m_arr[otherMatch]) {
      currentMatch++;
      otherMatch++;
    }

    if (otherMatch == other.m_length) {
      return currentMatch - other.m_length;
    }

    currentMatch++;
    otherMatch = 0;
  }

  return otherMatch == other.m_length ? m_length - other.m_length : -1;
}

String String::read() {
  char buffer[String::MAX_LENGTH];
  std::cin.getline(buffer, String::MAX_LENGTH);
  return String(buffer);
}

void String::write() const {
  std::cout << m_arr;
  return;
}

String::~String() {
  delete[] m_arr;
  m_arr = nullptr;
}

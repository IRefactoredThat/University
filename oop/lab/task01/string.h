#ifndef STRING_H
#define STRING_H

#include <cstddef>

class String {
private:
  int m_length;
  char *m_arr;

public:
  static constexpr int MAX_LENGTH = 10;

  String();
  String(const char *arr);
  String(const String &other);
  String &operator=(const String &other);

  size_t getLength() const;
  int getSubstringPos(const String &other) const;

  static String read();
  void write() const;

  ~String();
};

#endif // STRING_H

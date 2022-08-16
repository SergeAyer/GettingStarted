#pragma once

class Arithmetic {
public:
  Arithmetic(int a, int b) : _a(a), _b(b) 
  {
  }
 
  int add() 
  {
    return _a + _b;
  }

  int sub() 
  {
    return _a - _b;
  }

private:
  int _a;
  int _b;
};

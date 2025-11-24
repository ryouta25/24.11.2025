#include <iostream>

struct Planar
{
  int x = 0, y = 0;

  virtual int x() const; /*{ return x; }*/
  virtual int y() const; /*{ return y; }*/
  virtual int abc_sqr() const { return 0; }
  virtual ~Planar() = default;
};

struct Point : Planar
{
  virtual int x() const;
  virtual int y() const;
  virtual int abc_sqr() const;
  Point(int xx, int yy);
  virtual ~Point() = default;

private:
  int  data [2];
};

Planar* make(std::istream& is);
Planar* most_left(Planar** pls, size_t k);
Planar* make(size_t pl);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);

int main()
{
  Planar* pls[10] = {};
  size_t k = 0;

 //pls[k++] = make(std::cin);

  Planar* left = most_left(pls, k);

  for (size_t i = 0; i < 10; ++i)
  {
    try
    {
      pls[k] = make(i % 2);
    }
    catch (...)
    {
      free_planars(pls, k);
      return 2;
    }
    k++;
  }

  draw(most_left(pls,k));
  free_planars(pls, k);
}

Planar* make(size_t pl)
{
  switch (pl)
  {
    default:
      throw std::logic_error("bad id");
  }

  return nullptr;
}

void free_planars(Planar** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i)
     delete pls[i];
}

void draw(Planar* pl)
{
  std::cout << pl->x() << " ";
  std::cout << pl->y() << "\n";
}

Planar* most_left(Planar** pls, size_t k)
{
  return nullptr;
}

Point::Point(int xx, int yy) :
  Planar(),
  data{ xx, yy }
{

}

int Point::x() const
{
  return data[0];
}

int Point::y() const
{
  return data[1];
}

int Point::abc_sqr() const
{
  return x() * x() + y() * y();
}

Planar* make(size_t id)
{
  Planar* r = nullptr;
  switch (id)
  {
    case 0:
      r = new Point(0, 0);

    default:
      throw std::logic_error("bad id");
  }

  return r;
}

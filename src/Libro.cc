#include "../Include/Libro.h"

bool Libro::operator<(const Libro& libro2) const {
  return titulo_ < libro2.getTitulo();
}

bool Libro::operator>(const Libro& libro2) const {
  return titulo_ > libro2.getTitulo();

}

bool Libro::operator>=(const Libro& libro2) const {
  return titulo_ >= libro2.getTitulo();

}
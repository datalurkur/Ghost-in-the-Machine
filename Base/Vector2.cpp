#include <Base/Vector2.h>

std::ostream& operator<<(std::ostream &lhs, const Vector2 &rhs) {
    lhs << "Vector2";
    lhs << " " << rhs[0];
    lhs << " " << rhs[1];
    return lhs;
}
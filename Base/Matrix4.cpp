#include <Base/Matrix4.h>

const Matrix4 Matrix4::Identity(
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
);

Matrix4 Matrix4::MakeOrtho(float l, float r, float b, float t, float n, float f) {
    Matrix4 ret = Matrix4::Identity;

    ret[0][0] = (float)  2.0 / (r - l);
    ret[1][1] = (float)  2.0 / (t - b);
    ret[2][2] = (float) -2.0 / (f - n);

    ret[0][3] = -(r + l) / (r - l);
    ret[1][3] = -(t + b) / (t - b);
    ret[2][3] = -(f + n) / (f - n);

    return ret;
}

Matrix4 Matrix4::MakeTranslation(float x, float y, float z) {
	Matrix4 ret = Matrix4::Identity;

	ret[0][3] = x;
	ret[1][3] = y;
	ret[2][3] = z;

	return ret;
}

std::ostream& operator<<(std::ostream& lhs, const Matrix4 &rhs) {
	lhs << "Matrix4";
	for(int i=0; i<4; i++) {
		lhs << " " << rhs[i][0] << " " << rhs[i][1] << " " << rhs[i][2] << " " << rhs[i][3];
	}
	return lhs;
}
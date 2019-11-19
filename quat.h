typedef struct {
    float w;
    float x;
    float y;
    float z;
} quat;

quat quatnew(float w, float x, float y, float z) {
    quat q;
    q.w = w;
    q.x = x;
    q.y = y;
    q.z = z;
    return q;
}

quat quatinv(quat q) {
    return quatnew(q.w, -q.x, -q.y, -q.z);
}

quat quatnumpow(quat q, float n) {
    float w = q.w;
    float x = q.x;
    float y = q.y;
    float z = q.z;
    float t = n*acos(w);
    float s = sin(t)/sqrt(x*x + y*y + z*z);
    return quatnew(cos(t), s*x, s*y, s*z);
}

quat quatquatmul(quat a, quat b) {
    float aw = a.w;
    float ax = a.x;
    float ay = a.y;
    float az = a.z;

    float bw = b.w;
    float bx = b.x;
    float by = b.y;
    float bz = b.z;

    return quatnew(
        aw*bw - ax*bx - ay*by - az*bz,
        aw*bx + ax*bw + ay*bz - az*by,
        aw*by - ax*bz + ay*bw + az*bx,
        aw*bz + ax*by - ay*bx + az*bw
    );
}

quat quatslerp(quat a, quat b, float n) {
    float aw = a.w;
    float ax = a.x;
    float ay = a.y;
    float az = a.z;

    float bw = b.w;
    float bx = b.x;
    float by = b.y;
    float bz = b.z;

    if (aw*bw + ax*bx + ay*by + az*bz < 0) {
        aw = -aw;
        ax = -ax;
        ay = -ay;
        az = -az;
    }

    float w = aw*bw + ax*bx + ay*by + az*bz;
	float x = aw*bx - ax*bw + ay*bz - az*by;
	float y = aw*by - ax*bz - ay*bw + az*bx;
	float z = aw*bz + ax*by - ay*bx - az*bw;

	float t = n*acos(w);
	float s = sin(t)/sqrt(x*x + y*y + z*z);

    bw = cos(t);
	bx = s*x;
	by = s*y;
	bz = s*z;

    return quatnew(
        aw*bw - ax*bx - ay*by - az*bz,
		aw*bx + ax*bw - ay*bz + az*by,
		aw*by + ax*bz + ay*bw - az*bx,
		aw*bz - ax*by + ay*bx + az*bw
    );
}

float quatdot(quat a, quat b) {
    return a.w*b.w + a.x*b.x + a.y*b.y + a.z*b.z;
}

quat quataxisangle(vec3 v) {
    float x = v.x;
    float y = v.y;
    float z = v.z;
    float l = sqrt(x*x + y*y + z*z);
    x /= l;
    y /= l;
    z /= l;
    float s = sin(l/2);
    return quatnew(cos(l/2), s*x, s*y, s*z);
}

quat quateulerx(float a) {
    return quatnew(cos(a/2), sin(a/2), 0, 0);
}

quat quateulery(float a) {
    return quatnew(cos(a/2), 0, sin(a/2), 0);
}

quat quateulerz(float a) {
    return quatnew(cos(a/2), 0, 0, sin(a/2));
}

quat quatmat3(mat3 m) {
    float xx = m.xx;
    float xy = m.xy;
    float xz = m.xz;

    float yx = m.yx;
    float yy = m.yy;
    float yz = m.yz;

    float zx = m.zx;
    float zy = m.zy;
    float zz = m.zz;

    if (xx + yy + zz > 0) {
        float s = 2*sqrt(1 + xx + yy + zz);
        return quatnew(1/4*s, (yz - zy)/s, (zx - xz)/s, (xy - yx)/s);
    } else if (xx > yy && xx > zz) {
        float s = 2*sqrt(1 + xx - yy - zz);
		return quatnew((yz - zy)/s, 1/4*s, (yx + xy)/s, (zx + xz)/s);
    } else if (yy > zz) {
        float s = 2*sqrt(1 - xx + yy - zz);
		return quatnew((zx - xz)/s, (yx + xy)/s, 1/4*s, (zy + yz)/s);
    } else {
        float s = 2*sqrt(1 - xx - yy + zz);
		return quatnew((xy - yx)/s, (zx + xz)/s, (zy + yz)/s, 1/4*s);
    }
}

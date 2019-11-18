typedef struct {
    float xx;
    float xy;

    float yx;
    float yy;
} mat2;

mat2 mat2new(float xx, float yx, float xy, float yy) {
    mat2 m;
    
    m.xx = xx;
    m.xy = xy;

    m.yx = yx;
    m.yy = yy;

    return m;
}

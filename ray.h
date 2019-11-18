typedef struct {
    vec3 p;
    vec3 d;
} ray;

ray raynew(vec3 p, vec3 d) {
    ray r;
    r.p = p;
    r.d = d;
    return r;
}

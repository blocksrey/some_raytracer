typedef struct {
    float x;
    float y;
} vec2;

vec2 vec2new(float x, float y) {
    vec2 v;

    v.x = x;
    v.y = y;
    
    return v;
}

vec2 vec2vec2add(vec2 a, vec2 b) {
    return vec2new(a.x + b.x, a.y + b.y);
}

vec2 vec2vec2sub(vec2 a, vec2 b) {
    return vec2new(a.x - b.x, a.y - b.y);
}

float vec2dot(vec2 a, vec2 b) {
    return a.x*b.x + a.y*b.y;
}

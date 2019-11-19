#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "vec2.h"
#include "vec3.h"
#include "mat2.h"
#include "mat3.h"
#include "quat.h"
#include "ray.h"
#include "sphere.h"
#include "hit.h"

vec3 skycolor(vec3 d) {
    return vec3new(fmax(0, d.x), fmax(0, d.y), fmax(0, d.z));
}

int randrange(int a, int b) {
    return a + rand()%(1 + b - a);
}

int main() {
    //config
    vec3 worldlightposition = vec3unit(vec3new(-1, 3, -2));
    vec3 worldlightcolor = vec3new(1, 1, 1);
    vec3 cameraposition = vec3new(0, 0, 0);
    mat3 cameraorientation = mat3mat3mul(mat3mat3mul(euleranglesx(-0.1), euleranglesy(-0.2)), euleranglesz(0.1));
    vec2 viewsize = vec2new(1920, 1080);
    int colordepth = 255;
    //
    
    //store information
    int numspheres = 3;
    sphere spheres[numspheres];
    spheres[0] = spherenew(vec3new(1.2, -0.3, 4), 1.7);
    spheres[1] = spherenew(vec3new(-2.6, 0.5, 6), 0.9);
    spheres[2] = spherenew(vec3new(3.5, 4.7, 7.2), 1.4);

    vec3 trace(vec3 p, vec3 d) {
        for (int i = 0; i < numspheres; ++i) {
            sphere s = spheres[i];
            hit h = raypointsphere(raynew(p, d), s);
            if (h.s) {
                float lightamount = fmax(0, vec3dot(h.n, worldlightposition));
                return vec3nummul(worldlightcolor, lightamount);
            }
        }
        return skycolor(d);
    }

    //open file
    FILE *file = fopen("render.ppm", "wb");
    //create initial data
    fprintf(file, "P6\n%f %f\n%d\n", viewsize.x, viewsize.y, colordepth);

    //iterate through pixels
    for (int y = 0; y < viewsize.y; ++y) {
        for (int x = 0; x < viewsize.x; ++x) {
            //get world space direction of pixel
            vec3 castdirection = vec3unit(mat3vec3mul(cameraorientation, vec3new((2*x - viewsize.x)/viewsize.y, (viewsize.y - 2*y)/viewsize.y, 0.5)));
            //calculate color
            vec3 color = trace(cameraposition, castdirection);
            //write pixel color
            fwrite((char[]){colordepth*color.x, colordepth*color.y, colordepth*color.z}, 1, 3, file);
        }
    }

    //close file
    fclose(file);

    //terminate
    return 0;
}

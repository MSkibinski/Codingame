// https://www.codingame.com/training/easy/how-high-up-does-the-beer-go

#include <iostream>
#include <iomanip>

using namespace std;

const float PI = 3.14159265358979f;

class Glass {
    float bottomR, topR, H;

public:
    Glass(float bR, float tR, float h) : bottomR(bR), topR(tR), H(h) {}

    float getVolume(float h) {
        float r = bottomR;
        float R = r + h / H * (topR - bottomR);
        return h * PI * (r * r + r * R + R * R) / 3;
    }
};

int main()
{
    float bottom_radius;
    float top_radius;
    float glass_height;
    float beer_vol;
    cin >> bottom_radius >> top_radius >> glass_height >> beer_vol;

    Glass glass(bottom_radius, top_radius, glass_height);

    float low = 0;
    float high = glass_height;
    while (high - low > 0.01) {
        float middle = (low + high) / 2;
        float V = glass.getVolume(middle);
        if (V > beer_vol) high = middle;
        else low = middle;
    }

    cout << fixed << setprecision(1) << low << endl;
}

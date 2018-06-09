#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int nx = 200;
    int ny = 100;

    ofstream file;
    file.open("./assets/pic.ppm", ios::trunc);
    file << "P3\n" << nx << " " << ny << "\n255\n";
    
    for (int j = ny - 1; j >= 0; j--)
    {
        for (int i = 0; i < nx; i++)
        {
            float r = (float)i / (float)nx;
            float g = (float)j / (float)ny;
            float b = 0.5f;
            int ir = int(255.99f * r);
            int ig = int(255.99f * g);
            int ib = int(255.99f * b);
            file << ir << " " << ig << " " << ib << "\n";
        }
    }
    file.close();
    return 0;
}

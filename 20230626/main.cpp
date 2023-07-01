#include <stdio.h>

#define No_Calibration_Point 5

int i;
double y;

struct CalibrationData {
    double X[No_Calibration_Point];
    double Y[No_Calibration_Point];
}cal_data;

double linear_mapping(double x, struct CalibrationData cal_data)
{
    double x1 = cal_data.X[i];
    double x2 = cal_data.X[i + 1];
    double y1 = cal_data.Y[i];
    double y2 = cal_data.Y[i + 1];

    for (int j = 0; j < No_Calibration_Point - 1; j++) {
        if (x < cal_data.X[0])    i = 0;
        else if (x >= cal_data.X[j] && x < cal_data.X[j + 1]) i = j;
        else i = No_Calibration_Point - 2;
    }
    return y = y1 + (x - x1) * ((y2 - y1) / (x2 - x1));
}

int main()
{
    cal_data = {
        {0.0, 1.0, 2.0, 3.0, 4.0},
        {-30.0, -15.0, 0.0, 15.0, 30.0}  // y °ª
    };

    double x = -2;
    double mapped_value = linear_mapping(x, cal_data);
    printf("Mapped value: %.2f\n", mapped_value);

    return 0;
}
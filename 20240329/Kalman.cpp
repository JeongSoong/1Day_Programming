#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double A;
    double Q;
    double H;
    double R;
    double x_est;
    double P;
} KalmanFilter;

void KalmanFilter_Init(KalmanFilter* kf, double q, double r, double initial_est, double initial_err) {
    kf->A = 1.0;
    kf->Q = q;
    kf->H = 1.0;
    kf->R = r;
    kf->x_est = initial_est;
    kf->P = initial_err;
}

void KalmanFilter_Update(KalmanFilter* kf, double measurement) {
    double x_pred = kf->A * kf->x_est;
    double P_pred = kf->A * kf->P * kf->A + kf->Q;

    double K = P_pred * kf->H / (kf->H * P_pred * kf->H + kf->R);

    kf->x_est = x_pred + K * (measurement - kf->H * x_pred);
    kf->P = (1 - K * kf->H) * P_pred;
}

int main() {
    FILE* fpRead = fopen("C:\\Users\\문정수\\Desktop\\position_data.txt", "r");
    FILE* fpWrite = fopen("C:\\Users\\문정수\\Desktop\\filtered_position_data.txt", "w");

    if (!fpRead || !fpWrite) {
        printf("Failed to open the file\n");
        return -1;
    }

    KalmanFilter kf_x, kf_y, kf_z;
    KalmanFilter_Init(&kf_x, 0.1, 1.0, 0.0, 1.0);
    KalmanFilter_Init(&kf_y, 0.1, 1.0, 0.0, 1.0);
    KalmanFilter_Init(&kf_z, 0.1, 1.0, 0.0, 1.0);

    char buffer[1024];

    fgets(buffer, 1024, fpRead);
    fprintf(fpWrite, "Filtered_stateEstimate.x_y\tFiltered_stateEstimate.y_y\tFiltered_stateEstimate.z_y\n");

    while (fgets(buffer, 1024, fpRead) != NULL) {
        double x, y, z;
        if (sscanf(buffer, "%lf\t%lf\t%lf", &x, &y, &z) == 3) {
            KalmanFilter_Update(&kf_x, x);
            KalmanFilter_Update(&kf_y, y);
            KalmanFilter_Update(&kf_z, z);

            fprintf(fpWrite, "%lf\t%lf\t%lf\n", kf_x.x_est, kf_y.x_est, kf_z.x_est);
        }
    }

    fclose(fpRead);
    fclose(fpWrite);

    printf("Kalman filtering completed. Filtered data saved.\n");

    return 0;
}

#include "gem5/m5ops.h"
#include "executable_task.h"
#include <stdio.h>

void program_init(void);

void altitude_control_task(void);
int init_altitude_control_task(int arg_count, int *task_args);

void climb_control_task(void);
int init_climb_control_task(int arg_count, int *task_args);

void link_fbw_send(void);
int init_link_fbw_send(int arg_count, int *task_args);

void navigation_task( void );
int init_navigation_task(int arg_count, int *task_args);

void radio_control_task(void);
int init_radio_control_task(int arg_count, int *task_args);

void receive_gps_data_task(void);
int init_receive_gps_data_task(int arg_count, int *task_args);

void reporting_task(void);

void stabilisation_task(void);
int init_stabilisation_task(int arg_count, int *task_args);

// fly by wire tasks
void check_failsafe_task(void);
int init_check_failsafe_task(int arg_count, int *task_args);

void check_mega128_values_task(void);
int init_check_mega128_values_task(int arg_count, int *task_args);

void send_data_to_autopilot_task(void);
int init_send_data_to_autopilot_task(int arg_count, int *task_args);

void servo_transmit(void);

void test_ppm_task(void);
int init_test_ppm_task(int arg_count, int *task_args);

extern task _altitude_control_task;
extern task _climb_control_task;
extern task _link_fbw_send;
extern task _navigation_task;
extern task _radio_control_task;
extern task _receive_gps_data_task;
extern task _reporting_task;
extern task _stabilisation_task;
extern task _check_failsafe_task;
extern task _check_mega128_values_task;
extern task _send_data_to_autopilot_task;
extern task _servo_transmit;
extern task _test_ppm_task;


#define EXECUTE_TASK_WITH_INIT(task, valcount, valone, valtwo, valthree, valfour, valfive, valsix) \
    values[0] = valone; values[1] = valtwo; values[2] = valthree; values[3] = valfour; values[4] = valfive; values[5] = valsix; \
    /*printf("running " #task " with %i count %i %i %i %i %i %i\n", valcount, valone, valtwo, valthree, valfour, valfive, valsix);*/ \
    task.init(valcount, values); \
    m5_dump_stats(0, 0); task.function(); m5_dump_stats(0, 0); \


#define EXECUTE_TASK(task) \
    m5_dump_stats(0, 0); task.function(); m5_dump_stats(0, 0);

int main( int argc, char *argv[] ) {
    int values[6];

    program_init();

    EXECUTE_TASK_WITH_INIT(_test_ppm_task, 4, 1, 0, 1, 1, 0, 0)
    EXECUTE_TASK(_servo_transmit)
    EXECUTE_TASK_WITH_INIT(_send_data_to_autopilot_task, 4, 0, 1, 1, 1, 0, 0)
    EXECUTE_TASK_WITH_INIT(_check_mega128_values_task, 4, 0, 1, 0, 1, 0, 0)
    EXECUTE_TASK_WITH_INIT(_check_failsafe_task, 1, 0, 0, 0, 0, 0, 0)
    EXECUTE_TASK_WITH_INIT(_stabilisation_task, 1, 1, 0, 0, 0, 0, 0)
    EXECUTE_TASK(_reporting_task)
    EXECUTE_TASK_WITH_INIT(_receive_gps_data_task, 6, 0, 3, 0, 0, 0, 6)
    EXECUTE_TASK_WITH_INIT(_radio_control_task, 5, 1, 4, 1, 1, 0, 0)
    EXECUTE_TASK_WITH_INIT(_navigation_task, 2, 0, 3, 0, 0, 0, 0)
    EXECUTE_TASK_WITH_INIT(_link_fbw_send, 1, 1, 0, 0, 0, 0, 0)
    EXECUTE_TASK_WITH_INIT(_climb_control_task, 5, 0, 1, 7, 6, 1, 0)
    EXECUTE_TASK_WITH_INIT(_altitude_control_task, 1, 1, 0, 0, 0, 0, 0)

    return 0;
}

//
// Created by Oipo on 4/18/2018.
//

#ifndef EDIFYMRUNNER_EXECUTABLE_TASK_H
#define EDIFYMRUNNER_EXECUTABLE_TASK_H

typedef int (*functionPtr)();
typedef int (*initFunctionPtr)(int count, int *task_args);

typedef struct task {
    char *name;
    functionPtr function;
    initFunctionPtr init;
    struct task* next_task;
} task;

#endif //EDIFYMRUNNER_EXECUTABLE_TASK_H

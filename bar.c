#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep/usleep
#include <string.h>

const int BAR_LENGTH = 50;
const int MAX_TASKS = 5;

typedef struct {
    int id;
    int progress;
    int step;
} Task;

void print_bar(Task task) {
    int bars_to_show = (task.progress * BAR_LENGTH) / 100;
    printf("Task %d: [", task.id);
    for (int i = 0; i < BAR_LENGTH; i++) {
        if (i < bars_to_show)
            printf("#");
        else
            printf("-");
    }
    printf("] %d%%\n", task.progress);
}

int main() {
    Task tasks[MAX_TASKS];
    for (int i = 0; i < MAX_TASKS; i++) {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1;  // Random step between 1–5
    }

    int completed = 0;

    while (completed < MAX_TASKS) {
        system("clear");  // Use "cls" for Windows

        completed = 0;
        for (int i = 0; i < MAX_TASKS; i++) {
            if (tasks[i].progress < 100) {
                tasks[i].progress += tasks[i].step;
                if (tasks[i].progress > 100)
                    tasks[i].progress = 100;
            }
            print_bar(tasks[i]);
            if (tasks[i].progress == 100)
                completed++;
        }

        usleep(100000); // 0.1s delay
    }

    printf("\n✅ All tasks completed!\n");
    return 0;
}

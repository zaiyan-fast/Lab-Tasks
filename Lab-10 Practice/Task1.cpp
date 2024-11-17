#include <stdio.h>
#include <string.h>

struct Box{
    double weight;
    struct Box* nestedBoxes[5];
    int nestedBoxCount;
};

void makeBox(struct Box* box, double weight) {
    (*box).weight = weight;
    (*box).nestedBoxCount = 0;
}

void addNBox(struct  Box* parent, struct Box* child) {
    if ((*parent).nestedBoxCount < 5) {
        (*parent).nestedBoxes[(*parent).nestedBoxCount++] = child;
    }
}

double totalWeightCalc(struct Box* box) {
    double totalWeight = (*box).weight;
    for (int i = 0; i < (*box).nestedBoxCount; i++) {
        totalWeight += totalWeightCalc((*box).nestedBoxes[i]);
    }
    return totalWeight;
}

int main() {
    struct Box mainBox;
    makeBox(&mainBox, 0);

    struct Box box1;
    makeBox(&box1, 5);
    addNBox(&mainBox, &box1);

    struct Box nestedBox;
    makeBox(&nestedBox, 0);
    struct Box box2;
    makeBox(&box2, 3);
    addNBox(&nestedBox, &box2);
    addNBox(&mainBox, &nestedBox);

    printf("Total Weight: %.2f", totalWeightCalc(&mainBox));

    return 0;
}

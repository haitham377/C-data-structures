#include<vector.h>

int main(void) {
    vector v;
    int n = 1;

    initialize(&v, sizeof(int), n);

    int x = 10, y = 20, z = 100;

    push_back(&v, &x);
    push_back(&v, &y);
    push_back(&v, &z);

    for (int i = 0; i < v.size; i++) {
        int val = *(int *)((uint8_t *)v.data + v.element_size * i);
        printf("%i\n", val);
    }

    free_vec(&v);

    return 0;
}

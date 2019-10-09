#include <assert.h>

class Canary {
public:
    Canary();
    Canary(void* chunk_start, void* chunk_end);
    ~Canary();
    Canary(const Canary& canary);

    bool IsAlarm() const;

private:
    bool* left_wing;
    bool* right_wing;
};

Canary::Canary() {
    left_wing = nullptr;
    right_wing = nullptr;
}

Canary::Canary(void* chunk_start, void* chunk_end) {
    left_wing = (bool*) chunk_start;
    assert(left_wing);
    *left_wing = 0;

    right_wing = (bool*) chunk_end;
    assert(right_wing);
    *right_wing = 0;
}

Canary::~Canary() {
    left_wing = nullptr;
    right_wing = nullptr;
}

Canary::Canary(const Canary& canary) {
    left_wing = canary.left_wing;
    assert(left_wing);

    right_wing = canary.right_wing;
    assert(right_wing);
}

bool Canary::IsAlarm() const {
    assert(left_wing);
    assert(right_wing);

    return (*left_wing != 0 || *right_wing != 0);
}

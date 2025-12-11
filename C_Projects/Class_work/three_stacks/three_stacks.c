#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#include <assert.h>

#include "fixed_size_stack.h"
#include "fixed_size_stack.c"
#include "error.h"


typedef struct {
    unsigned disks_amount : 6;
    unsigned from_peg : 6;
    unsigned to_peg : 6;
    unsigned auxiliary_peg : 6;
	unsigned stage : 6;
} HanoiFrame;


void solve_hanoi_towers(unsigned disks_amount, unsigned from_peg, unsigned to_peg, unsigned auxiliary_peg);


void solve_hanoi_towers_iteratively(unsigned disks_amount, unsigned from_peg,
                                    unsigned to_peg, unsigned auxiliary_peg);

void HanoiFrame_print(HanoiFrame frame);

int main(){
#if 0
	unsigned disks_amount = 5;
	unsigned from_peg = 1;
    unsigned to_peg = 2;
	unsigned auxiliary_peg = 3;

	solve_hanoi_towers(disks_amount, from_peg, to_peg, auxiliary_peg);
#endif

#if 0
	const size_t STACK_MAX_SIZE = 10U;
    error_t error = SUCCESS;
	FixedSizeStack* stack = FixedSizeStack_new(STACK_MAX_SIZE, &error);
    
	FixedSizeStack_push(stack, 5u, &error);
    FixedSizeStack_push(stack, 101u, &error);
    FixedSizeStack_push(stack, 37u, &error);

	FixedSizeStack_print(stack, &error);

	FixedSizeStack_delete(&stack, &error);
#endif

#if 0
    HanoiFrame frame = { 3, 1, 2, 3, 0, };
    HanoiFrame_print(frame);

    unsigned x = 678903137;
    frame = *((HanoiFrame*)(&x));
    HanoiFrame_print(frame);

    unsigned y = *((unsigned *)(&frame));
    printf("y = %u\n", y);
    assert(x == y);
#endif

    printf("\n%s\n\n---------------------------Win---------------------------\n\n", __FILE__);
    return 0;
}


void solve_hanoi_towers(unsigned disks_amount, unsigned from_peg, unsigned to_peg, unsigned auxiliary_peg) {
    if (0 == disks_amount or 10 < disks_amount or from_peg < 1 or from_peg > 3
            or to_peg < 1 or to_peg > 3 or auxiliary_peg < 1 or auxiliary_peg > 3
            or to_peg == from_peg or to_peg == auxiliary_peg or from_peg == auxiliary_peg) {
        fprintf(stderr, "Wrong argument in %s\n", __FUNCTION__);
        return;
    }
	if (1 == disks_amount){
        printf("%u (1) %u\n", from_peg, to_peg);
        return;
    }
	solve_hanoi_towers(disks_amount - 1, from_peg, auxiliary_peg, to_peg);
    printf("%u (%u) %u\n", from_peg, disks_amount, to_peg);
	solve_hanoi_towers(disks_amount - 1, auxiliary_peg, to_peg, from_peg);
}

void solve_hanoi_towers_iteratively(unsigned disks_amount, unsigned from_peg,
                                    unsigned to_peg, unsigned auxiliary_peg){
    if (0 == disks_amount or 10 < disks_amount) {
        fprintf(stderr, "Wrong argument in %s\n", __FUNCTION__);
        return;
    }
	const size_t MAX_STACK_SIZE = (size_t)disks_amount;
	error_t error = SUCCESS;
	FixedSizeStack* stack = FixedSizeStack_new(MAX_STACK_SIZE, &error);
	assert(SUCCESS == error);

    HanoiFrame initial_frame;
    initial_frame.disks_amount = disks_amount;
    initial_frame.from_peg = from_peg;
    initial_frame.to_peg = to_peg;
    initial_frame.auxiliary_peg = auxiliary_peg;
    initial_frame.stage = 0u;

    FixedSizeStack_push(stack, *((unsigned*)(&initial_frame)), &error);
    assert(SUCCESS == error);

    while (true) {
        bool is_empty = FixedSizeStack_is_empty(stack, &error);
        assert(SUCCESS == error);
        if (is_empty) {
            break;
        }
        unsigned current_frame_u = FixedSizeStack_pop(stack, &error);
        assert(SUCCESS == error);
        HanoiFrame current_frame = *((HanoiFrame*)&current_frame_u);
        if (1U == current_frame.disks_amount) {
            printf("%u (1) %u\n", from_peg, to_peg);
            continue;
        }
        if (0U == current_frame.stage) {
            current_frame.stage = 1U;
            current_frame_u = *((unsigned*)&current_frame);
            FixedSizeStack_push(stack, current_frame_u, &error);
            assert(SUCCESS == error);
        
            HanoiFrame first_recursive_frame;
            first_recursive_frame.disks_amount = current_frame.disks_amount - 1U;
            first_recursive_frame.from_peg = current_frame.from_peg;
            first_recursive_frame.to_peg = current_frame.auxiliary_peg;
            first_recursive_frame.auxiliary_peg = current_frame.to_peg;
            first_recursive_frame.stage = 0U;
            
            unsigned first_recursive_frame_u = *((unsigned*)&first_recursive_frame);
            FixedSizeStack_push(stack, first_recursive_frame_u, &error);
            assert(SUCCESS == error);
        }

        else if (1U == current_frame.stage) {
            printf("%u (%u) %u\n", current_frame.from_peg,
                    current_frame.disks_amount, current_frame.to_peg);
            current_frame.stage = 2U;
            current_frame_u = *((unsigned*)&current_frame);
            FixedSizeStack_push(stack, current_frame_u, &error);
            assert(SUCCESS == error);

            HanoiFrame second_recursive_frame;
            second_recursive_frame.disks_amount = current_frame.disks_amount - 1U;
            second_recursive_frame.from_peg = current_frame.auxiliary_peg;
            second_recursive_frame.to_peg = current_frame.to_peg;
            second_recursive_frame.auxiliary_peg = current_frame.from_peg;
            second_recursive_frame.stage = 0U;

            unsigned second_recursive_frame_u = *((unsigned*)&second_recursive_frame);
            FixedSizeStack_push(stack, second_recursive_frame_u, &error);
            assert(SUCCESS == error);

        }
        else { // 2U == current_frame.stage
            assert(2U == current_frame.stage);
            continue;
        }
    }

	FixedSizeStack_delete(&stack, &error);
	assert(SUCCESS == error);
	assert(NULL == stack);
}

void HanoiFrame_print(HanoiFrame frame) {
    printf("disks_amount = %u\nfrom_peg = %u\nto_peg = %u\n"
          "auxiliary_peg = %u\nstage = %u\n\n", frame.disks_amount,
          frame.from_peg, frame.to_peg, frame.auxiliary_peg, frame.stage);
}
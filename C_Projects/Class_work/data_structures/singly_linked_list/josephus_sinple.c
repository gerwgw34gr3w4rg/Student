#include <stddef.h> // for size_t

size_t josephus_survivor_id(size_t participant_count, size_t step_size)
{
    // Guard against invalid input: return 0 (no valid 1-based id).
    if (participant_count == 0 || step_size == 0) {
        return 0;
    }

    // Zero-based survivor index for a circle of size 1 is 0.
    size_t zero_based_survivor_index = 0;

    // Build up to participant_count using the recurrence:
    // f(i) = (f(i-1) + step_size) % i, starting from i = 2.
    for (size_t current_circle_size = 2; current_circle_size <= participant_count; ++current_circle_size) {
        size_t effective_step = step_size % current_circle_size; // avoids huge additions
        zero_based_survivor_index = (zero_based_survivor_index + effective_step) % current_circle_size;
    }

    // Convert zero-based index to the required 1-based participant id.
    return zero_based_survivor_index + 1;
}
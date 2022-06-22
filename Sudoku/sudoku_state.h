#pragma once

void initialize_game_state(struct game_state emptyState);

void try_change_state(struct game_state* state, int targetState);

bool is_start_state(struct game_state state);

bool is_control_state(struct game_state state);

bool is_game_state(struct game_state state);

bool is_end_state(struct game_state state);

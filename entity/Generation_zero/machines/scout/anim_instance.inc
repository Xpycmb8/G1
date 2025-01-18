{animation
	{sequence "power_up_spawn"
		{file "power_up.anm"}
		{resume}
		{events 
			{1 "power_down_start_spawn"}
			{35 "joint_small"}
			{45 "joint_small"}
			{70 "power_down_leave"}
		}
	}
	{sequence "power_up" {resume}}
	{sequence "landing" 
		{movement}	
		{resume}
		{events 
			{1 "block_hover"}
			{80 "joint_small"}
			{93 "hover_off"}
		}
	}
	{sequence "take_off" 
		{movement}	
		{resume}
		{events 
			{70 "take_off_land"}
			{112 "hover"}
		}
	}
	{sequence "death_01" 
		{movement}	
		{resume}
	}
	{sequence "hover"
		{resume}
	}
	{sequence "hover_power_down" 
		{movement}	
		{resume}
	}
	{sequence "hover_power_down_ground" 
		{movement}	
		{resume}
	}
	{sequence "idle_to_lure" {resume}}
	{sequence "idle_to_scan" {resume}}
	{sequence "scan_narrow_loop" {resume}}
	{sequence "scan_to_idle" {resume}}
	{sequence "scan_wide_loop" 
		{events 	
			{1 "play_idle"}
			{15 "scanlines_start"}
			{17 "scanlines_hide"}
			{19 "scanlines_open"}
			{20 "scanlines_stop"}
			{40 "scanlines_start"}
			{42 "scanlines_hide"}
			{44 "scanlines_open"}
			{46 "scanlines_hide"}
			{48 "scanlines_open"}
			{50 "scanlines_hide"}
			{52 "scanlines_open"}
			{54 "scanlines_hide"}
			{56 "scanlines_open"}
			{58 "scanlines_hide"}
			{60 "scanlines_open"}
			{62 "scanlines_hide"}
			{64 "scanlines_open"}
			{66 "scanlines_hide"}
			{68 "scanlines_open"}
			{70 "scanlines_hide"}
			{72 "scanlines_open"}
			{74 "scanlines_hide"}
			{76 "scanlines_open"}
			{78 "scanlines_hide"}
			{80 "scanlines_stop"}
			{120 "leave_idle"}
		}
		{resume}
	}
	{sequence "hit_stumble_45ccw"
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{15 "joint_small"}
			{35 "replace_position_end"}
		}
	}
	{sequence "hit_stumble_45cw"	
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{15 "joint_small"}
			{35 "replace_position_end"}
		}
	}

	{sequence "hit_stumble_135ccw"
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{15 "joint_small"}
			{35 "replace_position_end"}
		}
	}

	{sequence "hit_stumble_135cw" 
		{movement}	
		{resume}
		{events 	
			{1 "replace_position_start"}
			{15 "joint_small"}
			{35 "replace_position_end"}
		}
	}
	{sequence "hit_stumble_planted_45ccw" {resume}}
	{sequence "hit_stumble_planted_45cw" {resume}}
	{sequence "move_end" {resume}}
	{sequence "turn_left" {resume}}
	{sequence "turn_right" {resume}}
	{sequence "move_update"
		{autostart}
		{events 
			{2 "move_update"}
		}
	}
	{sequence "speed_full" 
		{events 
			{1   "0_speed"}
			{10   "1_speed"}
			{20   "2_speed"}
			{30   "3_speed"}
			{40   "4_speed"}
			{50   "5_speed"}
			{60   "6_speed"}
			{70   "7_speed"}
			{80   "8_speed"}
			{90 "9_speed"}
		}
		{speed 1} 
		{resume}
	}
	{sequence "leds" 
		{speed 1} 
		{autostart}
	}
	{sequence "slope_right"
		{movement}	
		{resume}
		;{smooth 0.2}
		{events 
			{1 "slope_right_start"}
			{5 "joint_small"}
			{50 "joint_small"}
			{63 "slope_right_end"}
		}
	}
	{sequence "slope_right_reward"
		{file "slope_right.anm"}
		{movement}	
		{resume}
		;{smooth 0.2}
		{events 
			{1 "slope_right_reward_end"}
			{5 "joint_small"}
			{50 "joint_small"}
			{63 "slope_right_reward_start"}
		}
	}
	{sequence "slope_left"
		{movement}	
		{resume}
		;{smooth 0.2}
		{events 
			{1 "slope_left_start"}
			{5 "joint_small"}
			{50 "joint_small"}
			{63 "slope_left_end"}
		}
	}
	{sequence "idle_ground_loop"
		{speed 0.5} 
		{resume}
		; {events 
			; {1 ""}
			; {63 ""}
		; }
	}
	
	
	{sequence "engine_start" 
		{resume}
	}
	{sequence "engine_work" 
		{resume}
	}
	{sequence "engine_stop" 
		{resume}
	}
}

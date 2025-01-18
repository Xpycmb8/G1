	{animation
		{sequence "runstart_f" 
			{resume}	
			{speed 0.7}
			{events 
				{1 "idle_exit"}
				{8 "foot_micro"}
				{12 "foot_micro"}
				{16 "foot_micro"}
				{20 "foot_micro"}
				{24 "foot_micro"}
				{28 "foot_micro"}
				{30 "runstart_f"}
			}
		}
		{sequence "runstart_b" 
			{resume}	
			{file "runstart_f.anm"}
			{events 
				{4 "runstart_b"}
				{8 "foot_micro"}
				{12 "foot_micro"}
				{16 "foot_micro"}
				{20 "foot_micro"}
				{24 "foot_micro"}
				{28 "foot_micro"}
				{29 "idle_exit"}
			}
		}
		{sequence "runloop_fwd" 
			{resume}
			{events 
				{1 "idle_exit"}
				{2 "foot_micro"}
				{4 "foot_micro"}
				{6 "foot_micro"}
				{8 "foot_micro"}
				{11 "foot_micro"}
				{12 "runloop_f_small"}
			}
		}
		{sequence "runloop_brd" 
			{resume}
			{file "runloop_fwd.anm"}
			{events 
				{1 "runloop_b"}
				{2 "foot_micro"}
				{5 "foot_micro"}
				{8 "foot_micro"}
				{10 "foot_micro"}
				{15 "foot_micro"}
				{20 "foot_micro"}
				{24 "foot_micro"}
				{29 "idle_exit"}
			}
		}
		{sequence "runstop_f" 
			{resume} 
			{events 	
				{2 "foot_micro"}
				{4 "foot_micro"}
				{8 "foot_micro"}
				{9 "idle_enter"}
			}
		}
		{sequence "step_l_045" 	
			{resume} 
			{events 	
				{1 "idle_exit"}	
				{2 "foot_micro"}
				{4 "foot_micro"}
				{6 "foot_micro"}
				{8 "foot_micro"}
				{10 "foot_micro"}
				{12 "foot_micro"}
				{14 "foot_micro"}
				{16 "foot_micro"}
				{18 "foot_micro"}
				{20 "idle_enter"}
			}
		}
		{sequence "step_l_090" 	
			{resume} 
			{events	
				{1 "idle_exit"} 
				{2 "foot_micro"}
				{4 "foot_micro"}
				{6 "foot_micro"}
				{8 "foot_micro"}
				{10 "foot_micro"}
				{12 "foot_micro"}
				{14 "foot_micro"}
				{16 "foot_micro"}
				{18 "foot_micro"}
				{20 "idle_enter"}
			}
		}
		{sequence "step_r_045" 	
			{resume} 
			{events	
				{1 "idle_exit"} 
				{2 "foot_micro"}
				{4 "foot_micro"}
				{6 "foot_micro"}
				{8 "foot_micro"}
				{10 "foot_micro"}
				{12 "foot_micro"}
				{14 "foot_micro"}
				{16 "foot_micro"}
				{18 "foot_micro"}
				{20 "idle_enter"}
			}
		}
		{sequence "step_r_090" 
			{resume} 
			{events 	
				{1 "idle_exit"} 
				{2 "foot_micro"}
				{4 "foot_micro"}
				{6 "foot_micro"}
				{8 "foot_micro"}
				{10 "foot_micro"}
				{12 "foot_micro"}
				{14 "foot_micro"}
				{16 "foot_micro"}
				{18 "foot_micro"}
				{20 "idle_enter"}
			}
		}
		{sequence "idle_loop" 
			{speed 0.5}
			{resume}
			{events 	
				{20 "idle_mur_mur"}
				{40 "idle_mur_mur"}
				{60 "idle_mur_mur"}
				{80 "idle_mur_mur"}
				{100 "idle_mur_mur"}
				{120 "idle_mur_mur"}
				{140 "idle_mur_mur"}
				{160 "idle_mur_mur"}
				{180 "idle_mur_mur"}
				{200 "idle_mur_mur"}
				{220 "idle_mur_mur"}
				{240 "idle_mur_mur"}
				{260 "idle_mur_mur"}
				{280 "idle_mur_mur"}
				{300 "idle_mur_mur"}
				{340 "idle_mur_mur"}
				{360 "idle_mur_mur"}
			}
		}
		{sequence "power_down"
			{speed 0.5}
			{events 
				{1 "power_down_start"}
				{3 "restart_micro"}
				{7 "restart_micro"}
				{11 "restart_micro"}
				{15 "restart_micro"}
				{18 "restart_micro"}
			}
			{resume}
		}
		{sequence "power_up"
			{resume}
			{events 
				{1 "power_down_check"}
				{30 "power_down_leave"}
			}
		}
		{sequence "attack_melee_jump_close"
			{movement}	
			;{smooth 0.05} 
			{resume}
			{events 	
				{1 "block_all"}
				{2 "jump_micro"}
				{3 "fly"}
				{4 "combat_micro_armed_enter"}
				;{7 "combat_micro_armed"}
				{9 "shock_hit_micro"}
				;{18 "combat_micro_armed"}
				{28 "combat_micro_armed_leave"}
				{29 "jump_end"}
			}
		}
		{sequence "attack_melee_jump_land" 
			{resume}		
			{events 	
				{8 "grounded"}
				{19 "landed"}
			}
		}
		{sequence "micro_combat"}
	}

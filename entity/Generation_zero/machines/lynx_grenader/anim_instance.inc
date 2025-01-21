{animation
	{sequence "power_up_spawn"
		{speed 0.5}
		{file "power_up.anm"}
		{movement}
		{resume}
		{events 
			{1 "power_down_start_spawn"}
			{5 "restart_clunk"}
			{14 "power_down_leave"}
		}
	}
	{sequence "power_down"
		{speed 0.4}
		{events 
			{1 "power_down_start"}
			{5 "restart_clunk"}
			{10 "restart_clunk"}
		}
		{resume}
	}
	{sequence "power_up"
		{speed 0.5}
		{resume}
		{movement}
		{events 
			{1 "power_down_check"}
			{5 "restart_clunk"}
			{14 "power_down_leave"}
		}
	}
	{sequence "turn_left" 
		{speed 0.2}
		{resume}
	}
	{sequence "engine_on" 
		{speed 1}
		{resume}
	}
	{sequence "brake_on"
		{speed 1}
		{events 
			{3 "brake_fx_lynx_start"}
			{6 "brake_fx_lynx_stop"}
		}
		{resume}
	}
	{sequence "health"
		{resume}
		{events 	
			{5 "5heal"} 
			{20 "20heal"} 
			{40 "40heal"} 
			{70 "70heal"} 
			{99 "explosion_lynx"} 
		}
	}
	{sequence
		"jump"
		{speed 1}
		{events 
			{10 "jump_pillar"}
			{18 "pillar_up"}
		}
	}
	; {sequence "saw_attack" 
		; ;{movement}
		; {speed 0.5}
		; {resume}
		; {events 
			; {1 "start_attack"}
			; {15 "saw_attack_start"}
		; }
	; }
	{sequence "saw_attack_start" 
		{resume}
		{events 
			{5 "saw_attack_start"}
		}
	}
	{sequence "saw_attack_loop" 
		{resume}
	}
	{sequence "saw_attack_stop" 
		{resume}
	}
	{sequence "saw_attack_move" 
		{movement}
		{speed 1}
		{resume}
	}
	{sequence "saw_attack_backup" 
		{movement}
		{speed 1}
		{resume}
	}
	{sequence "saw_attack_contact" 
;		{movement}
		{speed 1}
		{resume}
	}
	{sequence "open_saw" 
		{speed 1}
		{resume}
		{events 
			{1 "open_saw"}
		}
	}
	{sequence "rotate_saw" 
		{speed 1}
		{resume}
	}
	{sequence "close_saw" 
		{speed 1}
		{resume}
	}
}

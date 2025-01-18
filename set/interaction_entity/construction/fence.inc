{"fence"
	{inflammation_time 4}
	{on bullet_hit
		{if stuff "shell fg"
			{bullet_detonate}
		}
	}
	{on pierce
		{if stuff "zenite"
			{if rand 0.2		
				{call "break"}
			}
		else stuff "zenite fg"
			{if rand 0.6		
				{call "break"}
			}
		else stuff "shell fg"
			{call "break"}
		else stuff "shell"
			{if rand 0.8		
				{call "break"}
			}
		else stuff "rocketlauncher"
			{if rand 0.4		
				{call "break"}
			}
		}
	}
	{on break_armor
		;{call "break"}
	}
	{on contact ;sync
		{if can_crush
			{if effector "small_auto"
				{if min_speed 15
					{if rand 0.4
						{call "break"}
					}
				}
			else effector "pest_base"
			else
				{call "break"}
			}
		else effector "air_part"
			{call "break"}
		else effector "big part"
			{call "break"}
		}
	}
	{on "burn_volume"
		{if not burned
			{if volume "body"
				{burn volume fx "smoke_dead_tree1" time 40 2 even_law}
				{delay 36 "break_delay" {call "break"}}
			}
		}
	}
	{on "disable_volumes"
		{volumes disable visible bullet contact blast touch}
	}
}

{"wood fence"
	{on "break"
		{call "disable_volumes"}
		{spawn "wood_crush_small" "root"}
		{delay 0.2 {delete}}
	}
}

{"wood fence big"
	{on "break" overload
		{call "disable_volumes"}
		{spawn "wood_crush_big" "root"}
		{delay 0.2 {delete}}
	}
}

{"concrete fence"
	{inflammation_time 10000}
	{on "break"
		{call "disable_volumes"}
		{spawn "stone_hit_small" "root"}
		{spawn "concrete_fence_destroy" "root" x}
		{delay 0.2 {delete}}
	}
}

{"steel fence"
	{inflammation_time 10000}
	{on "break"
		{call "disable_volumes"}
		{spawn "car_die_particle" "root"}
		{delay 0.2 {delete}}
	}
}

{"animated_crush"
	{on "break" overload
		{kill_delay "break_delay"}
		{burn stop}
		{call "disable_volumes"}
		{area disable}
		{tex_mod "x"}
		{ani_play "crush" callback}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
	}
}

{"animated_crush_gate"
	{on break_armor
		{if name "pierce"
			{call "break"}
		}
	}
	{on "break" overload
		{kill_delay "break_delay"}
		{burn stop}
		{call "disable_volumes"}
		{area disable}
		{ani_play "crush" callback}
	}
	{on animation_end "crush"
		{update_shadow}
		{update_visibility_patch}
	}
}

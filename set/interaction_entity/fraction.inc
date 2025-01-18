{"fraction" ; from shotgun
	{on spawn
;;		{impulse up 0 dir -3 6 forward 10 40 com  fx -5 10}
		{volumes disable contact}	
		{delay 0
			{volumes enable contact}	
		}
		{if rand 0.5 
			{add_view 	"sl_shot2" 	"fraction" "root"}
			{view start "fraction"}
		else rand 0.2
			{add_view 	"sl_shot3" 	"fraction" "root"}
			{view start "fraction"}
		else rand 0.2
			{add_view 	"sl_shot4" 	"fraction" "root"}
			{view start "fraction"}
		}
		{delay 1.3
			{view pause "fraction"}
		}		
		{gravity 0}
		{delay 1 {gravity 1}}	
		{delay 2 {gravity 3}}	
		{delay 5 {delete}}
	}
	{on contact sync
		{if not effector "fraction_small"
			{view pause "fraction"}
			{if rand 0.1 
				{impulse up 3 1 dir -1 1 forward 2 1 com  fx 1}
			else
				{delete}
			}
			{if effector "vehicle"
				{if rand 0.1 
					{impulse up 3 1 dir -1 1 forward 2 1 com  fx 1}
					{spawn "metal_hit_sl"}
				else
					{delete}
				}
			}
		}
	}
	{on ground_hit
		{spawn "ex_bul_fr"}
		{delete}
	}
}

{"dragon_fire" ; from shotgun dragon_fire
	{on spawn
		{volumes disable contact}	
		{delay 0.1
			{volumes enable contact}	
		}
		{add_view 	"fx_trace_bullet_dragon" 	"fraction" "root"}
		{view start "fraction"}
		{delay 0.7 {gravity 1}}	
		{delay 1 
			{scale from 1 to 0.1 time 0.4}
			{gravity 0.5}
		}	
		{delay 1.6 {delete}}
	}
	{on contact
		{if not effector "fraction_small"
			{if rand 0.1 
				{impulse up 3 1 dir -1 1 forward 2 1 com  fx 1}
			else
				{delete}
			}
			{if effector "vehicle"
				{if rand 0.1 
					{impulse up 3 1 dir -1 1 forward 2 1 com  fx 1}
					{spawn "metal_hit_sl"}
				else
					{delete}
				}
			}
			{fire radius 0.1 time 0.5 heating 1}
			{spawn "dragonfire_hit"}
			{delete}
		}
	}
	{on ground_hit
		{fire radius 0.1 time 0.1 heating 0.2}
		{spawn "dragonfire_hit"}
		{spawn "ex_bul_fr"}
		{delete}
	}
}

{"fraction_round"
	{on spawn
		{volumes disable contact}	
		{delay 0
			{volumes enable contact}	
		}
		{impulse up 2 1 cx 2 1 cy 2 1 rnd_dir 20 10 no_position}
		{if rand 0.2 
			{add_view 	"fx_trace_bullet_round" 	"fraction" "basis"}
		else rand 0.1 
			{add_view 	"fx_trace_hit_big" 			"fraction" "basis"}
		}
		{view start "fraction"}
		{delay 1 {gravity 1}}	
		{delay 2 {gravity 3}}	
		{delay 5 {delete}}
	}
	{on ground_hit
		{spawn "ex_bul_fr"}
		{delete}
	}
	{on contact
		{if not effector "fraction_small"
			{view pause "fraction"}
			{if rand 0.1 
				{impulse up 3 1 dir -1 1 forward 2 1 com  fx 1}
			else
				{delete}
				{volumes disable contact}	
			}
		}
	}
}



{"fraction_view"
	{on spawn
		{if rand 0.4
			{add_view 	"smoke_aero_4_small" 	"fraction" "frost"}
			{view start "fraction"}
			{delay 0.2 0.1 "t"
				{view pause "fraction"}
			}
		else rand 0.7 
			{add_view 	"slicer_tail2" 	"fraction2" "frost"}
			{view start "fraction2"}
			{delay 0.3 0.1 "w"
				{view pause "fraction2"}
			}
		else rand 0.1 
			{add_view 	"flash_fuse_small" 	"fraction3" "frost"}
			{view start "fraction3"}
			{delay 0.15 0.1 "f"
				{view pause "fraction3"}
			}
		}
		{delay 2
			{delete}
		}
	}
}
{"fraction_view2"
	{on spawn
		{if rand 0.4
			{add_view 	"smoke_aero_4_small" 	"fraction" "frost"}
			{view start "fraction"}
			{delay 0.2 0.1 "t"
				{view pause "fraction"}
			}
		else rand 0.7 
			{add_view 	"slicer_tail2" 	"fraction2" "frost"}
			{view start "fraction2"}
			{delay 0.3 0.1 "w"
				{view pause "fraction2"}
			}
		else rand 0.1 
			{add_view 	"flash_fuse_small" 	"fraction3" "frost"}
			{view start "fraction3"}
			{delay 0.15 0.1 "f"
				{view pause "fraction3"}
			}
		}
		{delay 2
			{delete}
		}
	}
}

{"fraction_view_shade"
	{on spawn
		{impulse up 0 dir -1 1 forward 100 30 com  fx -2 4}
		{volumes "Body_vol" enable contact}
		{add_view 	"bullet_shade" 	"fraction" "fraction_v"}
		{view start "fraction"}
		{delay 1
			{delete}
		}
	}
}
	
	
{"fraction_v_expl"
	{on spawn
		;{impulse	up 0.4 dir 0.5 cx 0 2 cy 0 2 fx 0 25 fy 0 25 fz 0 8 }
		{impulse up 2 1 dir 5 2 cx 5 2 cy 5 2 rnd_dir 30 no_position}
		{physics_work 1}
		{volumes "body" enable contact}
		;{gravity 2}
		{if rand 0.1 
			{add_view 	"sl_shot2" 	"fraction" "root"}
			{view start "fraction"}
			{delay 0.2 0.1 "t"
				{view pause "fraction"}
				;{spawn "metal_hit_sl"}
			}
		else rand 0.05 
			{add_view 	"slicer_tail" 	"fraction2" "root"}
			{view start "fraction2"}
			{delay 0.3 0.1 "w"
				{view pause "fraction2"}
			}
		else rand 0.02 
			{add_view 	"flash_fuse_small" 	"fraction3" "root"}
			{view start "fraction3"}
			{delay 0.15 0.1 "f"
				{view pause "fraction3"}
			}
		}
		{delay 1.8 {delete}}
	}
	{on contact
		{if effector "vehicle"
			{delete}
			{spawn "metal_hit_sl"}
		else effector "flesh"
			{delete}
			{spawn "bloodsparks_big"}
		else effector "concrete"
			{delete}
			{spawn "stone_hit_sl"}
		else effector "fence"
			{delete}
			{spawn "stone_hit_sl"}
		else effector "wood"
			{delete}
			{spawn "hay_hit_small3"}
		}
	}
	{on ground_hit
		{spawn "ex_bul_fr"}
		{delete}
	}
}

{"fraction_s"
	{on spawn
		{volume disable bullet}
		{delay 1
			{volume enable bullet}
		}
;		{impulse up 0 dir -3 6 forward 100 30 com  fx -5 10}
		{impulse up 0 dir -1 1 forward 100 30 com  fx -2 4}
		{if rand 0.1 
			{add_view 	"sl_shot2" 	"fraction" "root"}
			{view start "fraction"}
			{delay 0.2 0.1 "t"
				{view pause "fraction"}
				;{spawn "metal_hit_sl"}
			}
		else rand 0.05 
			{add_view 	"slicer_tail" 	"fraction2" "root"}
			{view start "fraction2"}
			{delay 0.3 0.1 "w"
				{view pause "fraction2"}
			}
		else rand 0.02 
			{add_view 	"flash_fuse_small" 	"fraction3" "root"}
			{view start "fraction3"}
			{delay 0.15 0.1 "f"
				{view pause "fraction3"}
			}
		}
		{delay 1.8 {delete}}
	}
	{on contact
		{if effector "vehicle"
			{delete}
			{spawn "metal_hit_sl"}
		else effector "flesh"
			{delete}
			{spawn "bloodsparks_big"}
		else effector "concrete"
			{delete}
			{spawn "stone_hit_sl"}
		else effector "fence"
			{delete}
			{spawn "stone_hit_sl"}
		else effector "wood"
			{delete}
			{spawn "hay_hit_small3"}
		}
	}
	{on ground_hit
		{spawn "ex_bul_fr"}
		{delete}
	}
}

{"fraction_anim"
	{on spawn
		{ani_play "rotate" loop}
		{impulse up 0 dir 0 forward 100 30 com  fx 0}
		{volumes "Body" enable contact}
		{add_view 	"scharka" 	"fraction" "rotate_link"}
		{view start "fraction"}
		{delay 2 {delete}}
	}
	{on contact
		{if effector "vehicle"
			{delete}
			{spawn "metal_hit_sl"}
		else effector "flesh"
			{delete}
			{spawn "bloodsparks_big"}
		else effector "concrete"
			{delete}
			{spawn "stone_hit_sl"}
		else effector "fence"
			{delete}
			{spawn "stone_hit_sl"}
		else effector "wood"
			{delete}
			{spawn "hay_hit_small3"}
		}
	}
	{on ground_hit
		{spawn "ex_bul_fr"}
		{delete}
	}
}



{"wound_engine"
	{on spawn
		{if not "texmods"
			{if rand 0.5
				{scale from 0.2 to 0.2 time 0.1}
			else rand 0.2
				{scale from 0.3 to 0.3 time 0.1}
			else rand 0.1
				{scale from 0.4 to 0.4 time 0.1}
			}
			{set "texmods" 1}
			{if rand 0.3
				{tex_mod "1"}
			else rand 0.3
				{tex_mod "2"}
			else rand 0.3
				{tex_mod "3"}
			else rand 0.3
				{tex_mod "4"}
			else rand 0.3
				{tex_mod "5"}
			else rand 0.3
				{tex_mod "6"}
			else rand 0.3
				{tex_mod "7"}
			else rand 0.3
				{tex_mod "8"}
			else rand 0.3
				{tex_mod "9"}
			else rand 0.3
				{tex_mod "10"}
			else rand 0.3
				{tex_mod "11"}
			else rand 0.3
				{tex_mod "12"}
			else rand 0.3
				{tex_mod "13"}
			else rand 0.3
				{tex_mod "14"}
			else rand 0.3
				{tex_mod "15"}
			}
		}
	}
}

{"wound"
	{on spawn
		{if not "texmods"
			{set "texmods" 1}
			{if rand 0.3
				{tex_mod "1"}
			else rand 0.3
				{tex_mod "2"}
			else rand 0.3
				{tex_mod "3"}
			else
				{tex_mod "4"}
			}
		}
		{add_view "wound_fx_stone00"	"wound00"	"basis"	}
		{add_view "wound_fx_stone01"	"wound01"	"basis"	}
		{if rand 0.3 
			{view start "wound00"}
		else rand 0.3
			{view start "wound01"}
		}
		{delay 2
			{view stop "wound00"}
			{view stop "wound01"}
		}	
	}
}

{"steel_wound"
	{on pierce
		{if stuff "bullet big"
			{spawn "wound_steel_pierce_big" }	
		else stuff "bullet normal ap"
			{spawn "wound_steel_pierce" }	
		else stuff "bullet sp"
			{spawn "wound_steel_pierce" }	
		}
	}
	{on bullet_hit	
		{if stuff "bullet big"
			{spawn "wound_steel_hit_big" }	
		else stuff "zenite fg"
			{spawn "wound_steel_pierce_big" }	
			{spawn "wound_steel_hit_big" }	
		else stuff "bullet normal ap"
			{spawn "wound_steel_hit" }	
		else stuff "bullet sp"
			{spawn "wound_steel_hit" }	
		}
	}
	{on contact
		{if effector "wound_blood"
			{spawn "decal_blood_fx" }
		else effector "wound_shotgun"
			{spawn "wound_shotgun" }

		}
	}	
}



{"wound_fire_spawn"
	{on spawn	
		{spawn "fraction_set" offset 0 0.5 3.5}
		{spawn "fraction_set" offset 0 0.5 3.5}
		{spawn "fraction_set" offset 0 0.5 3.5}
		{spawn "fraction_set" offset 0 0.5 3}
		{spawn "fraction_set" offset 0 0.5 3}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 0.5 3.5}
		{spawn "fraction_set" offset 0 0.5 3.5}
		{spawn "fraction_set" offset 0 0.5 3.5}
		{spawn "fraction_set" offset 0 0.5 3}
		{spawn "fraction_set" offset 0 0.5 3}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 -0.5 2}
		{spawn "fraction_set" offset 0 0 1}
		{spawn "fraction_set" offset 0 0 1}
		{spawn "fraction_set" offset 0 0 1}
		{spawn "fraction_set" offset 0 0 1}
		{spawn "fraction_set" offset 0 0 1}
		{spawn "fraction_set" offset 0 0 7}
		{spawn "fx_piece_fire" offset 0 0 4.5}
		{spawn "fx_piece_fire" offset 0 0 4.5}
		{spawn "fx_piece_fire" offset 0 0 4.5}
		{spawn "fx_piece_fire" offset 0 0 4.5}
		{spawn "fx_piece_fire" offset 0 0 4.5}
		{spawn "fx_piece_fire" offset 0 0 4.5}
		{if rand 0.2 
			{spawn "fraction_set" offset 0 0.5 4}
			{spawn "fraction_set" offset 0 0.5 4}
			{spawn "fraction_set" offset 0 -0.5 4}
			{spawn "fraction_set" offset 0 -0.5 4}
			{spawn "fx_piece_fire" offset 0 0 2}
			{spawn "fx_piece_fire" offset 0 0 2}
		else rand 0.1
			{spawn "fraction_set" offset 0 0 7}
			{spawn "fraction_set" offset 0 0 1}
			{spawn "fraction_set" offset 0 0 7}
			{spawn "fraction_set" offset 0 0 7}
			{spawn "fraction_set" offset 0 0 7}
			{spawn "fx_piece_fire" offset 0 0 4}
			{spawn "fx_piece_fire" offset 0 0 4}
			{spawn "fx_piece_fire" offset 0 0 4}
			{spawn "fx_piece_fire" offset 0 0 4}
		}
		{delete}
	}
}
{"wound_fire_spawn_big"
	{on spawn	
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_set" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{spawn "fraction_thermite_fast" random_position 25 }
		{delete}
	}
}

{"wound_fire"
	{on spawn	
		{impulse up 2 0.5 rnd_dir 2}
		{delay 3
			{delete}
		}	
	}
	{on contact
		{delete}
	}
	{on ground_hit
		{if rand 0.6 
			{spawn "impact_burnmark_01_blend"}
		else rand 0.3
			{spawn "impact_burnmark_02_blend"}
		}
		{delete}
	}
}


{"decal_blood_ground"
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "blood_step"}
				{call "blood_step"}
			}
		}
	}
}

{"wound_other"
	{on spawn
		{if rand 0.5
			{scale from 0.2 to 0.2 time 0.1}
		else rand 0.2
			{scale from 0.3 to 0.3 time 0.1}
		else rand 0.1
			{scale from 0.4 to 0.4 time 0.1}
		}
		{if rand 0.3
			{tex_mod "01"}
		else rand 0.3
			{tex_mod "02"}
		else rand 0.3
			{tex_mod "03"}
		else rand 0.3
			{tex_mod "04"}
		}
	}
}

{"wound_blood"
	{on spawn
		{if rand 0.5
			{scale from 0.1 to 0.1 time 0.1}
		else rand 0.2
			{scale from 0.15 to 0.15 time 0.1}
		else 
			{scale from 0.2 to 0.2 time 0.1}
		}
		{if rand 0.3
			{tex_mod "01"}
		else rand 0.3
			{tex_mod "02"}
		else rand 0.3
			{tex_mod "03"}
		else rand 0.3
			{tex_mod "04"}
		else rand 0.3
			{tex_mod "05"}
		else rand 0.3
			{tex_mod "06"}
		else rand 0.3
			{tex_mod "07"}
		else rand 0.3
			{tex_mod "08"}
		else rand 0.3
			{tex_mod "09"}
		else rand 0.3
			{tex_mod "10"}
		}
	}
}


{"weight"
	{on spawn 
		{set "armor" 1}
	}
	{on contact
		{if effector "fraction_small" ;дробь
			{if not linked
				{impulse up 0.2 dir 0.3 0.1}
			}
		}
	}
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "bullet big"
				{impulse up 0.2 dir 0.3 0.1}
			else stuff "bullet noview"
				{impulse dir 0.1}
			else stuff "bullet"
				{impulse up 0.1 dir 0.1 0.1}
			}
		}
	}
}

{"weight_not_armor"
	{on contact
		{if effector "fraction_small" ;дробь
			{if not linked
				{impulse up 0.01 dir 0.04}
			}
		}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "bullet big"
				{impulse up 0.15 dir 0.3 0.1}
			else stuff "atgm_launcher"
				{impulse up 2 dir 30 fx 8 cx 4 2 cy 4 2}
			else stuff "shell_big"
				{impulse up 2 dir 30 fx 8 cx 4 2 cy 4 2}
			else stuff "shell_minimum"
				{impulse up 2 dir 6 fx 2 cx 1 cy 1}
			else stuff "zenite fg"
				{impulse up 1.1 dir 2.4 0.2}
			else stuff "zenite"
				{impulse up 1.1 dir 1.2 0.2}
			else stuff "bullet noview"
				{impulse dir 0.01}
			else stuff "bullet"
				{impulse up 0.1 dir 0.1 0.1}
			}
		}
	}
}


{"stuff no_blast_physics"
	{on "blast_physics" overload}
}

{"physics_barrel"
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "shell fg"
				{spawn "ex_old_dust"}
				{impulse up 0.4 0.2 dir 1 0.5}
			else stuff "rocketlauncher"
				{spawn "ex_old_dust"}
				{burn fx "smoke_aero_small" time 1 fake}				
				{burn fx "smoke_aero_2_small" time 3 fake}				
				{burn fx "smoke_aero_3_small" time 7 fake}				
				{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
			else stuff "hmgun"
				{impulse up 0.9 0.5 dir 5 2.5}
			else stuff "bullet sm_ic"
				{impulse up 0.7 0.4 dir 3 2.5}
			else stuff "bullet big"
				{impulse up 0.7 0.4 dir 3 2.5}
			else stuff "bullet normal ap"
				{impulse up 0.5 0.3 dir 2 1.5}
			else stuff "bullet normal"
				{impulse up 0.4 0.2 dir 1 0.5}
			else stuff "bullet noview"
				{impulse dir 0.01}
			else stuff "bullet"
				{impulse up 0.4 0.2 dir 1 0.5}
			}
		}
	}
}

{"small_stuff"
;	{on contact
;		{if effector "fraction_small" ;дробь
;			{if not linked
;				(define "disable_contact_0")
;				{impulse up 0.1 dir 0.2 0.1}
;			}
;		}
;	}
	{on "crush_container"
;		{impulse up 2 1 cx 0 1 cy 0 1}
		{impulse dir 2 1 up 2 1 dir 7 2 cx 0 0.5 cy 0 0.5}
	}
	{on "drop_item"
		{impulse dir 2 1 cx 0 1 cy 0 1}
	}
	{on blast_hit
		{if not linked
			{call "blast_physics"}
		}
	}
	{on bullet_hit
		{if not linked
			{if stuff "shell fg"
				{impulse up 0.4 0.2 dir 1 0.5}
			else stuff "rocketlauncher"
				{impulse up 0.9 0.5 dir 5 2.5}
			else stuff "hmgun"
				{impulse up 1.9 0.5 dir 5 2.5}
			else stuff "bullet sm_ic"
				{impulse up 1.2 0.4 dir 3 2.5}
			else stuff "bullet big"
				{impulse up 1.6 0.4 dir 3 2.5}
			else stuff "bullet normal ap"
				{impulse up 0.7 0.5 dir 2 1.5}
			else stuff "bullet normal"
				{impulse up 0.9 0.2 dir 1 0.5}
			else stuff "bullet"
				{impulse up 0.7 0.2 dir 1 0.5}
			}
		}
	}
}

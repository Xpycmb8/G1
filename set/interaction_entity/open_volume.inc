{"radio_signal"
	{on spawn
		{tags add "radio_signal"}
		{delay 25
			{delete}
		}
	}
	{on overlap begin
		{if effector "radio_bomb"
			{with_effector
				{call "_explosion"}
				{tags add "_1"}
			}		
		}		
	}
}
{"posion_gas"
	{on spawn
		{burn volume "gas_vol" fx "gas_smoke_volume" time 25 fake even_law}
		{tags add "posion_gas"}
		{delay 20
			{delete}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "contact_gases"}
				{call "contact_gases"}
			}	
		}		
	}
}
{"posion_gas_scale"
	{on spawn
		{burn volume "gas_vol" fx "gas_smoke_volume" time 25 fake even_law}
		{scale from 1 to 4 time 46}
		{tags add "posion_gas"}
		{delay 46
			{delete}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "contact_gases"}
				{call "contact_gases"}
			}	
		}		
	}
}

{"grenade_danger"
	{on spawn
		{tags add "grenade_danger"}
		{delay 3
			{delete}
		}
	}
	{on overlap begin
		{if effector "human"
			{delay 1
				{delete}
			}
			{with_effector
				{tags add "danger_grenade"}
				{call "danger_grenade"}
			}
		}		
	}
}

{"pool_oil"
	{inflammation_time 8}
	{on spawn
		{volumes "crown_big" disable all}
		{ani_play "oil" 0.6}
		{tags add "pool_oil"}
		{delay 5
			{volumes "crown_big" enable contact bullet blast visible}
		}
		{delay 120
			{delete}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown_big" time 20}
			{blastwave c4 0.4 r0 6 r1 6}	
			{fire radius 4 time 1 heating 1}
			{spawn "open_gas_l_fx" "pool"}	
			{spawn "heavy_revebration" "pool"}	
			{delete}	
		}
	}	
	{on bullet_hit
		{if not "burned"
			{if rand 0.1
				{set "burned" 1}
				{blastwave c4 0.4 r0 6 r1 6}	
				{blastwave c4 0.1 r0 12 r1 12}	
				{fire radius 4 time 1 heating 1}
				{spawn "open_gas_l_fx" "pool"}	
				{delete}
			}
		}
	}
	{on "burn"
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown_big" time 20}
			{tags add "blast"}
			{spawn "open_gas_l_fx" "pool"}	
			{blastwave c4 1 r0 6 r1 6}	
			{fire radius 4 time 1 heating 1}
		}
	}
	{on "blast_volume"
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown_big" time 20}
			{blastwave c4 0.4 r0 6 r1 6}	
			{fire radius 4 time 0.5 heating 1}
			{spawn "open_gas_l_fx" "pool"}	
			{delete}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "open_gas_l"}
				{call "open_gas"}
			}
		else effector "match"
			{call "blast_volume"}
		}		
	}
}

{"open_gas_l"
	{inflammation_time 4}
	{on spawn
		{tags add "open_gas_l"}
		{delay 25
			{delete}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown" time 8}
			{blastwave c4 0.4 r0 6 r1 6}	
			{fire radius 4 time 1 heating 1}
			{spawn "open_gas_l_fx" "basis"}	
			{spawn "heavy_revebration" "basis"}	
			{delete}	
		}
	}	
	{on bullet_hit
		{if rand 0.1
			{if not "burned"
				{set "burned" 1}
				{blastwave c4 0.4 r0 6 r1 6}	
				{blastwave c4 0.1 r0 12 r1 12}	
				{fire radius 4 time 1 heating 1}
				{spawn "open_gas_l_fx" "basis"}	
				{delete}
			}
		}
	}
	{on "burn"
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown" time 8}
			{tags add "blast"}
			{spawn "open_gas_l_fx" "basis"}	
			{blastwave c4 1 r0 6 r1 6}	
			{fire radius 4 time 1 heating 1}
		}
	}
	{on "blast_volume"
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown" time 8}
			{blastwave c4 0.4 r0 6 r1 6}	
			{fire radius 4 time 0.5 heating 1}
			{spawn "open_gas_l_fx" "basis"}	
			{delete}
		}
	}
	{on overlap begin
		{if effector "hdr_quiet"
			{with_effector
				{tags add "contact_gases"}
			}	
		}		
		{if effector "human"
			{with_effector
				{tags add "open_gas_l"}
				{call "open_gas"}
			}
		else effector "match"
			{call "blast_volume"}
		}		
	}
}

{"open_gas_verylarge"
	{inflammation_time 12}
	{on spawn
		{tags add "open_gas_verylarge"}
		{delay 60
			{delete}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown" time 16}
			{blastwave c4 1 r0 12 r1 12}	
			{fire radius 9 time 1 heating 1}
			{spawn "open_gas_vl_fx" "basis"}	
			{spawn "heavy_revebration" "basis"}	
			{delete}	
		}
	}	
	{on bullet_hit
		{if rand 0.1
			{if not "burned"
				{set "burned" 1}
				{blastwave c4 0.4 r0 6 r1 6}	
				{blastwave c4 0.1 r0 12 r1 12}	
				{fire radius 4 time 1 heating 1}
				{spawn "open_gas_l_fx" "basis"}	
				{delete}
			}
		}
	}
	{on "burn"
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown" time 12}
			{tags add "blast"}
			{spawn "open_gas_vl_fx" "basis"}	
			{blastwave c4 1 r0 12 r1 12}	
			{fire radius 8 time 1 heating 1}
		}
	}
	{on "blast_volume"
		{if not "burned"
			{set "burned" 1}
			{fire volume "crown" time 8}
			{blastwave c4 0.4 r0 6 r1 6}	
			{fire radius 4 time 0.5 heating 1}
			{spawn "open_gas_l_fx" "basis"}	
			{delete}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "open_gas_verylarge"}
				{call "open_gas"}
			}
		else effector "match"
			{call "blast_volume"}
		}		
	}
}

{"open_gas_m"
	{inflammation_time 4}
	{on spawn
		{tags add "open_gas_m"}
		{delay 15
			{delete}
		}
	}
	{on "burn"
		{if not "burned"
			{set "burned" 1}
			{tags add "blast"}
			{spawn "open_gas_m_fx" "basis"}	
			{blastwave c4 0.2 r0 3 r1 3}	
			{fire radius 2 time 1 heating 1}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{blastwave c4 0.1 r0 4 r1 4}	
			{fire radius 2 time 0.5 heating 1}
			{spawn "open_gas_m_fx" }	
			{delete}
		}
	}	
	{on bullet_hit
		{if rand 0.1
			{if not "burned"
				{set "burned" 1}
				{blastwave c4 0.1 r0 4 r1 4}	
				{fire radius 2 time 0.5 heating 1}
				{spawn "open_gas_m_fx" }	
				{delete}
			}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "open_gas_m"}
				{call "open_gas"}
			}	
		}		
	}
}

{"open_gas_s"
	{inflammation_time 4}
	{on spawn
		{tags add "open_gas_s"}
		{delay 7
			{delete}
		}
	}
	{on "burn"
		{if not "burned"
			{set "burned" 1}
			{tags add "blast"}
			{spawn "open_gas_s_fx" "basis"}	
			{blastwave c4 0.1 r0 2 r1 2}	
			{fire radius 0.5 time 1 heating 1}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{blastwave c4 0.1 r0 2 r1 2}	
			{fire radius 0.5 time 0.5 heating 1}
			{spawn "open_gas_s_fx" }	
			{delete}
		}
	}	
	{on bullet_hit
		{if rand 0.1
			{if not "burned"
				{set "burned" 1}
				{blastwave c4 0.1 r0 2 r1 2}	
				{fire radius 0.5 time 0.5 heating 1}
				{spawn "open_gas_s_fx" }	
				{delete}
			}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "open_gas_s"}
				{call "open_gas"}
			}	
		}		
	}
}

{"open_gas_ph"
	{inflammation_time 0}
	{on spawn
		{burn volume "body" fx "smoke_cover-up_big_white" time 7 fake even_law}	
		{if rand 0.4
			{gravity 0.3}
		else rand 0.1
			{gravity 0.8}
		}
		{delay 7
			{delete}
		}
	}
	{on "burn"
		{if not "burned"
			{if rand 0.4
				{spawn "open_gas_s_fx" }	
				{blastwave c4 0.6 r0 2 r1 2}	
				{fire radius 0.5 time 3 heating 1}
			else rand 0.3
				{spawn "distant_small_expl"}			
				{blastwave c4 3 r0 5 r1 5}	
				{fire radius 2 time 3 heating 1}
				{spawn "open_gas_m_fx" }	
			}
			{set "burned" 1}
			{delete}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{blastwave c4 0.1 r0 2 r1 2}	
			{fire radius 0.5 time 2 heating 1}
			{spawn "open_gas_s_fx" }	
			{delete}
		}
	}	
	{on bullet_hit
		{if rand 0.1
			{if not "burned"
				{set "burned" 1}
				{blastwave c4 0.1 r0 2 r1 2}	
				{fire radius 0.5 time 0.5 heating 1}
				{spawn "open_gas_s_fx" }	
				{delete}
			}
		}
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "open_gas_s"}
				{call "open_gas"}
			}	
		}		
	}
}

{"open_gas_scale"
	;{inflammation_time 0}
	{on spawn
		{volumes disable contact}
		{delay 2
			{volumes enable contact}
		}
		{scale from 1 to 4 time 7}
		{burn volume "body" fx "smoke_gas_drop_burn" time 20 fake}	
		{delay 20
			{delete}
		}
	}
	{on "burn" overload
	}
	{on blast_hit overload
	}	
	{on bullet_hit overload
	}
	{on overlap begin
		{if effector "human"
			{with_effector
				{tags add "contact_gases"}
				{call "contact_gases"}
			}	
		}		
	}
}

{"open_smoke_scale"
	;{inflammation_time 0}
	{on spawn
		{volumes disable contact}
		{delay 2
			{volumes enable contact}
		}
		{scale from 1 to 4 time 7}
		{burn volume "body" fx "smoke_drop_burn" time 20 fake}	
		{delay 20
			{delete}
		}
	}
	{on "burn" overload
	}
	{on blast_hit overload
	}	
	{on bullet_hit overload
	}
	{on overlap begin overload
	}
}


{"open_fuel_s"
	{inflammation_time 0.1}
	{on spawn
		{tags add "open_fuel_s"}
		{delay 25
			{delete}
		}
	}
	{on blast_hit 
		{if not "burned"
			{set "burned" 1}
			{blastwave c4 0.1 r0 2 r1 2}	
			{fire radius 0.5 time 0.5 heating 1}
			{spawn "open_gas_s_fx" }	
			{delete}
		}
	}	
	{on bullet_hit
		{if rand 0.1
			{if not "burned"
				{set "burned" 1}
				{blastwave c4 0.1 r0 2 r1 2}	
				{fire radius 0.5 time 0.5 heating 1}
				{spawn "open_gas_s_fx" }	
				{delete}
			}
		}
	}
	{on "burn"
		{if not burned
			{set "burned" 1}
			{spawn "open_gas_s_fx" "basis"}	
			{blastwave c4 0.1 r0 2 r1 2}	
			{fire radius 0.5 time 1 heating 1}
			{delete}
		}
	}
}

{"tinnitus_small"
	{on spawn
		;{impulse up 0.2 dir 0.5 cx 1 cy 1 rnd_dir 0.5 no_position}
		{tags add "tinnitus_small"}
		{delay 1
			{delete}
		}
	}
	; {on overlap begin ; close 20-02-2022 00-10
		; {if effector "human"
			; {with_effector
				; {call "tinnitus_small_expl"}
			; }
		; }		
	; }
}

;{"interior"
;	{on spawn
;		{tags add "interior"}
;	}
;	{on overlap begin
;		{tags add "interior"}
;		{if effector "human"
;			{with_effector
;				{tags add "interior"}
;			}
;		}		
;	}
;	{on overlap end
;		{if effector "human"
;			{with_effector
;				{tags remove "interior"}
;			}
;		}		
;	}
;}

{"detect"
	{on overlap begin
		{if effector "human"
			{with_effector
				{call "detect"}
			}	
		}		
	}
	{on spawn
		{delay 3
			{delete}
		}
	}
}


{"detect_zone"
	{on overlap begin
		{if effector "human"
			{with_effector
				{call "detect"}
			}	
		}		
	}
	{on spawn
		{delay 10
			{delete}
		}
	}
}


; {"overlap_land"
	; {on spawn
		; {update_visibility_patch}
		; {area disable}
		; {land off}
	; }
	; {on overlap begin sync
		; {land on}
		; {kill_delay "land"}
		; {tags add "land"}
		; {update_visibility_patch}
		; {area enable}
		; {delay 10 "land"
			; {tags remove "land"}
			; {update_visibility_patch}
			; {area disable}
			; {land off}
		; }
	; }
; }

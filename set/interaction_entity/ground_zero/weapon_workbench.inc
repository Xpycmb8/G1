{"small_ammo"
	{on spawn
		(define "ammo_list"
			{add_view "%0" "%0" "basis"}
			{view hide "%0"}		
		)
		("ammo_list" args magazine_rifle_270_with_fmj)
		("ammo_list" args magazine_rifle_270_with_soft)
		("ammo_list" args bullet7x64_fmj_view)
		("ammo_list" args bullet7x64_soft_view)
		{delay 0
			{call "update_mass"}
		}
	}
	{on "update_mass"
		{if min_mass 1
		else min_mass 0.22
		else min_mass 0.2104 ;soft 270 with mags rifle 270
			{tags add "magazine_rifle_270_with_soft"}
			{view show "magazine_rifle_270_with_soft"}
		else min_mass 0.2054 ;simple 270 with mags rifle 270
			{tags add "magazine_rifle_270_with_fmj"}
			{view show "magazine_rifle_270_with_fmj"}
		else min_mass 0.0604 ;270 soft bullet x5
			{view show "bullet7x64_soft_view"}
		else min_mass 0.0554 ;simple 270 fmj bullet x5
			{view show "bullet7x64_fmj_view"}
		else
			{start_sound "human/anim/pickup/small/"}
			{delete}
		}
		{delay_effect 0.5 "update_mass"}
	}
}
{"weapon_workbench"
	{on spawn
		{call "update_mass"}
	}
	{on "build"
		{tags add "build"}
	}
	{on animation_end "build"
		(define "mass_build"
			{if tagged "%item"
				{spawn "%item" "weapon_bone_spawn" x}
				{spawn "weapon_workbench" "basis" x}
				{delete}					
			}
		); масса сборки            спавн
		("mass_build" item(rifle270_stock_grade1_scope_1_4x_24mm) )
		("mass_build" item(rifle270_stock_grade1_scope_4_8x_32mm) )
		("mass_build" item(rifle270_stock_grade1_scope_4_8x_42mm) )
		("mass_build" item(rifle270_stock_grade1) )
		("mass_build" item(rifle_scope_1_4x_24mm) )
		("mass_build" item(rifle_scope_4_8x_32mm) )
	}
	{on "update_mass"
		{if tagged "build"
			{ani_play "build" callback}
			{tags remove "build"}
		}
;		(define "mass_search"
		{if min_mass 20		
		else min_mass 4.11
		else min_mass 4.0999    ;scope with rifle4_8_42mm 0.59
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_scope_4_8x_42mm" 							"rifle_scope_4_8x_32mm" 	"sight_bone"}
				{add_view "rifle_270_vis" 									"rifle270_stock_grade1" 	"weapon_bone"}
				{view show "rifle270_stock_grade1"}
				{view show "rifle_scope_4_8x_42mm"}
				{tags add "rifle270_stock_grade1_scope_4_8x_42mm"}
			}
		else min_mass 4.081
		else min_mass 4.0799;scope with rifle4_8(4.3355)4.0800
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_scope_4_8x_32mm" 							"rifle_scope_4_8x_32mm" 	"sight_bone"}
				{add_view "rifle_270_vis" 									"rifle270_stock_grade1" 	"weapon_bone"}
				{view show "rifle270_stock_grade1"}
				{view show "rifle_scope_4_8x_32mm"}
				{tags add "rifle270_stock_grade1_scope_4_8x_32mm"}
			}
		else min_mass 4.061
		else min_mass 4.0599;scope with rifle1_4(4.1100)4.0600  
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_scope_1_4x_24mm" 							"rifle_scope_1_4x_24mm" 	"sight_bone"}
				{add_view "rifle_270_vis" 									"rifle270_stock_grade1" 	"weapon_bone"}
				{view show "rifle270_stock_grade1"}
				{view show "rifle_scope_1_4x_24mm"}
				{tags add "rifle270_stock_grade1_scope_1_4x_24mm"}
			}
		else min_mass 3.511
		else min_mass 3.509;stock(3.5100)3.7155
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_270_vis" "rifle270_stock_grade1" "weapon_bone"}
				{view show "rifle270_stock_grade1"}
				{tags add "rifle270_stock_grade1"}
			}
		else min_mass 0.591
		else min_mass 0.5899	;sight_rifle4_8_42(0.5900)
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_scope_4_8x_42mm" "rifle_scope_4_8x_42mm" "sight_bone"}
				{view show "rifle_scope_4_8x_42mm"}
				{tags add "rifle_scope_4_8x_42mm"}
			}
		else min_mass 0.571
		else min_mass 0.5699	;sight_rifle4_8(0.5700)
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_scope_4_8x_32mm" "rifle_scope_4_8x_32mm" "sight_bone"}
				{view show "rifle_scope_4_8x_32mm"}
				{tags add "rifle_scope_4_8x_32mm"}
			}
		else min_mass 0.551
		else min_mass 0.549;sight_rifle1_4(0.5500)
			{call "clear_tags"}
			{delay 0
				{add_view "rifle_scope_1_4x_24mm" "rifle_scope_1_4x_24mm" "sight_bone"}
				{view show "rifle_scope_1_4x_24mm"}
				{tags add "rifle_scope_1_4x_24mm"}
			}
		else 
		;	{call "close_box"}
			{call "clear_tags"}
		}
		{delay_effect 1 "update_mass"}
	}
	{on "clear_tags"	
		{view hide "rifle270_stock_grade1"}
		{view hide "rifle_scope_1_4x_24mm"}
		{view hide "rifle_scope_4_8x_32mm"}
		{view hide "rifle_scope_4_8x_42mm"}
		{view hide "rifle270_stock_grade1_scope_1_4x_24mm"}
		{view hide "rifle270_stock_grade1_scope_4_8x_32mm"}
		{view hide "rifle270_stock_grade1_scope_4_8x_42mm"}
		{tags remove "rifle270_stock_grade1_scope_1_4x_24mm"}			
		{tags remove "rifle270_stock_grade1_scope_4_8x_32mm"}			
		{tags remove "rifle270_stock_grade1_scope_4_8x_42mm"}			
		{tags remove "rifle270_stock_grade1"}			
		{tags remove "rifle_scope_1_4x_24mm"}			
		{tags remove "rifle_scope_4_8x_32mm"}			
		{tags remove "rifle_scope_4_8x_42mm"}			
	}
}

{"ammo_workbench"
	{on spawn
		{ani_wind "open" end }
		{call "update_mass"}
		{add_view "magazine_rifle_empty" "magazine_rifle_empty" "mag_bone"}
		{view hide "magazine_rifle_empty"}		
		{add_view "casing_bullet7x64" "casing_bullet7x64" "casing_bone"}
		{view hide "casing_bullet7x64"}		
		{add_view "item_flammeable" "item_flammeable" "item_bone"}
		{view hide "item_flammeable"}		
		(define "ammo_list"
			{add_view "%0" "%0" "ammo_bone"}
			{view hide "%0"}		
		)
		("ammo_list" args bullet7x64_soft)
		("ammo_list" args bullet7x64_fmj)
		(define "bullet_list"
			{add_view "%0" "%0" "bullet_bone"}
			{view hide "%0"}		
		)
		("bullet_list" args bullet_7x64_fmj)
		("bullet_list" args bullet_7x64_soft)
		
	}
	{on "build"
		{delay 1.5
			{start_sound "push/ammobox/open/"}
			{ani_play "open" }
		}
		{delay 1
			{start_sound "push/toolcase/open/"}
			{tags add "build"}
		}
	}
	{on animation_end "build"
		{spawn "ammo_workbench" "basis" x {ani_wind "build" begin}}
		{delete}					
	}
	{on animation_event "build"
		(define "mass_build"
			{if tagged "gun_powder"
				{if tagged "casing_bullet_7x64"
					{if tagged "%item"
						{call "build_bullet"}
						{spawn "%add" "%bone" %pivot}
					}
				}
			}
			{if tagged "magazine_rifle_empty"
				{if tagged "%item"
					{spawn "%add" "%bone" %pivot}
				}
			}
		); масса сборки            спавн
		("mass_build" item(bullet7x64_soft) 	bone(mag_bone) 				pivot(x)			add(magazine_rifle_270_with_soft_add)) ;ready mags
		("mass_build" item(bullet7x64_fmj)  	bone(mag_bone) 				pivot(x)			add(magazine_rifle_270_with_fmj_add) ) ;ready mags
;-----------------------------------------------------------------------------------------------------------------------
		("mass_build" item(bullet_7x64_soft) 	bone(build_bullet_bone) 	pivot(x)			add(7x64_bullet_ammo_soft_add)) ;bullet_item
		("mass_build" item(bullet_7x64_fmj)  	bone(build_bullet_bone) 	pivot(x)			add(7x64_bullet_ammo_fmj_add) ) ;bullet_item
	}
	
	{on "update_mass"
		{if tagged "build"
			{ani_play "build" callback}
			{tags remove "build"}
		}
		{if min_mass 1
		else min_mass 0.22
			{call "close_box"}
			{call "clear_tags"}
		else min_mass 0.2106 
		else min_mass 0.2104 ;soft 270 with mags rifle 270
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "magazine_rifle_empty"}
				{tags add "bullet7x64_soft"}
			}
			{view show "bullet7x64_soft"}
			{view show "magazine_rifle_empty"}
		else min_mass 0.2056 
		else min_mass 0.2054 ;simple 270 with mags rifle 270
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "magazine_rifle_empty"}
				{tags add "bullet7x64_fmj"}
			}
			{view show "bullet7x64_fmj"}
			{view show "magazine_rifle_empty"}
		;---------------------magazine------------------------------			
		else min_mass 0.1501 
		else min_mass 0.1499 ;mags rifle 270
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "magazine_rifle_empty"}
			}
			{view show "magazine_rifle_empty"}
		;---------------------bullet_with_mag------------------------------			
		else min_mass 0.0606
		else min_mass 0.0604 ;soft 270
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet7x64_soft"}
			}
			{view show "bullet7x64_soft"}
		else min_mass 0.0556
		else min_mass 0.0554 ;simple 270
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet7x64_fmj"}
			}
			{view show "bullet7x64_fmj"}
		;---------------------craft_bullet_item------------------------------
		else min_mass 0.0456
		else min_mass 0.0454 ;craft ;soft 270-5 bullet 0.0455
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_soft"}
				{tags add "casing_bullet_7x64"}
				{tags add "gun_powder"}
			}
			{view show "bullet_7x64_soft"}
		else min_mass 0.0431
		else min_mass 0.0429 ;craft ;fmj 270-5 bullet 0.0430
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_fmj"}
				{tags add "casing_bullet_7x64"}
				{tags add "gun_powder"}
			}
			{view show "bullet_7x64_fmj"}
		;----------------
		else min_mass 0.0456
		else min_mass 0.0454 ;craft ;soft 270-5 bullet 0.0455
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_soft"}
				{tags add "casing_bullet_7x64"}
				{tags add "gun_powder"}
			}
			{view show "bullet_7x64_soft"}
		else min_mass 0.0431
		else min_mass 0.0429 ;craft ;fmj 270-5 bullet 0.0430
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_fmj"}
				{tags add "casing_bullet_7x64"}
				{tags add "gun_powder"}
			}
			{view show "bullet_7x64_fmj"}
		
		;item-----------------------------------------------------------
		else min_mass 0.0401
		else min_mass 0.0399 ;bullet soft item 0.0400
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_soft"}
				{tags add "casing_bullet_7x64"}
			}
			{view show "bullet_7x64_soft"}
			{view show "casing_bullet7x64"}
		else min_mass 0.0376
		else min_mass 0.0374 ;bullet fmj with casing 0.0375
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_fmj"}
				{tags add "casing_bullet_7x64"}
			}
			{view show "bullet_7x64_fmj"}
			{view show "casing_bullet7x64"}
		
		else min_mass 0.0251
		else min_mass 0.0249	 ;bullet soft
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_soft"}
			}
			{view show "bullet_7x64_soft"}
		else min_mass 0.0226
		else min_mass 0.0224 ;bullet fmj 
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "bullet_7x64_fmj"}
			}
			{view show "bullet_7x64_fmj"}
		else min_mass 0.0206
		else min_mass 0.0204 ;casing 7x64 x5  with powder   0.0205
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "casing_bullet_7x64"}
				{tags add "gun_powder"}
			}
			{view show "casing_bullet7x64"}
			{view show "item_flammeable"}
		else min_mass 0.0151
		else min_mass 0.0149 ;casing 7x64 x5     0.0150
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "casing_bullet_7x64"}
			}
			{view show "casing_bullet7x64"}
		else min_mass 0.0056
		else min_mass 0.0054 ;craft ;powder x5 0.0055
			{call "close_box"}
			{call "clear_tags"}
			{delay 0
				{tags add "gun_powder"}
			}
			{view show "item_flammeable"}
		else
			{call "clear_tags"}
			{call "hide_all"}
		}
		{delay_effect 1 "update_mass"}
	}
	{on "close_box"
		{if not tagged "close"
			{start_sound "push/ammobox/close/"}
			{ani_play "open" -1 resume }
			{tags add "close"}
		}
	}
	{on "build_bullet"
		{view hide "bullet_7x64_fmj"}
		{view hide "bullet_7x64_soft"}
		{view hide "casing_bullet7x64"}
	}
	{on "hide_all"
		{view hide "bullet_7x64_fmj"}
		{view hide "bullet_7x64_soft"}
		{view hide "casing_bullet7x64"}
		{view hide "item_flammeable"}		
		{view hide "magazine_rifle_empty"}
		{view hide "magazine_rifle_270_with_fmj"}		
		{view hide "magazine_rifle_270_with_soft"}		
		{view hide "bullet7x64_fmj"}
		{view hide "bullet7x64_soft"}
	}
	{on "clear_tags"	
		{tags remove "gun_powder"}
		{tags remove "casing_bullet_7x64"}
		{tags remove "bullet_7x64_soft"}
		{tags remove "bullet_7x64_fmj"}
		{tags remove "bullet7x64_fmj"}
		{tags remove "bullet7x64_soft"}
		{tags remove "magazine_rifle_empty"}
		{tags remove "magazine_rifle_270_with_fmj"}
		{tags remove "magazine_rifle_270_with_soft"}
	}
}

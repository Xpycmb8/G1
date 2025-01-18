(define "check_tex"
	{if tex_mod "%skin"							
		{delay 2 
			{tex_mod "%skin" }
		}
	}
)
{"small_stuff"
	{on ground_hit
		(define "link_up"
			{if not linked
				{tags add "laser_off_up"}
				{tags add "light_off_up"}
				("check_tex" skin(1) )					
				("check_tex" skin(2) )					
				("check_tex" skin(3) )					
				("check_tex" skin(4) )					
				("check_tex" skin(5) )					
				("check_tex" skin(6) )					
				("check_tex" skin(7) )					
				("check_tex" skin(8) )					
				("check_tex" skin(9) )					
				("check_tex" skin(10) )					
				("check_tex" skin(d) )					
				("check_tex" skin(w) )					
				("check_tex" skin(s) )					
				{delay 0.1 
					{tex_mod "laser_up_off"}
					{tex_mod "light_up_off"}
				}
				{tags remove "light_on_up"}
				{tags remove "laser_on_up"}
				{tags remove "light_on_up_%0"}
				{tags remove "laser_on_up_%0"}
				{ani_play "caps_laser_up" -0.2}
				{ani_play "caps_front_up" -0.2}
				{view hide	"fx_laser_set_up_%0"}
				{view stop	"fx_laser_set_up_%0"}
				{view hide	"fx_light_set_up_%0"}
				{view stop	"fx_light_set_up_%0"}
			}
		)
		("link_up" args lasercylinder1)
		("link_up" args lasercylinder3)
		("link_up" args lasercylinder4)
		("link_up" args flashlight_sf)
		("link_up" args peq10)
		("link_up" args peq15)
		("link_up" args laser1mw)
		("link_up" args laser5mw)
		("link_up" args tactical_laser)
		("link_up" args tactical_laser2)
		("link_up" args zenitco)
		("link_up" args liner)
		(define "link_r"
			{if not linked
				;{if tagged "attach_r_%0"
					{tags add "laser_off_r"}
					{tags add "light_off_r"}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
					{delay 0.1 
						{tex_mod "laser_l_off"}
						{tex_mod "light_l_off"}
						{tex_mod "laser_r_off"}
						{tex_mod "light_r_off"}
						{tex_mod "laser_off"}
						{tex_mod "light_off"}
					}
					{tags remove "light_on_r"}
					{tags remove "laser_on_r"}
					{tags remove "light_on_r_%0"}
					{tags remove "laser_on_r_%0"}
					{ani_play "caps_laser_r" -0.2}
					{ani_play "caps_front_r" -0.2}
					{view hide	"fx_laser_set_r_%0"}
					{view stop	"fx_laser_set_r_%0"}
					{view hide	"fx_light_set_r_%0"}
					{view stop	"fx_light_set_r_%0"}
				;}
			}
		)
		("link_r" args lasercylinder1)
		("link_r" args lasercylinder3)
		("link_r" args lasercylinder4)
		("link_r" args flashlight_sf)
		("link_r" args peq10)
		("link_r" args peq15)
		("link_r" args laser1mw)
		("link_r" args laser5mw)
		("link_r" args tactical_laser)
		("link_r" args tactical_laser2)
		("link_r" args zenitco)
		("link_r" args liner)
		(define "link_l"
			{if not linked
				{if tagged "attach_l_%0"
					{tags add "laser_off_l"}
					{tags add "light_off_l"}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
					{delay 0.1 
						{tex_mod "laser_l_off"}
						{tex_mod "light_l_off"}
					}
					{tags remove "light_on_l"}
					{tags remove "laser_on_l"}
					{tags remove "light_on_l_%0"}
					{tags remove "laser_on_l_%0"}
					{ani_play "caps_laser_l" -0.2}
					{ani_play "caps_front_l" -0.2}
					{view hide	"fx_laser_set_l_%0"}
					{view stop	"fx_laser_set_l_%0"}
					{view hide	"fx_light_set_l_%0"}
					{view stop	"fx_light_set_l_%0"}
				}
			}
		)
		("link_l" args lasercylinder1)
		("link_l" args lasercylinder3)
		("link_l" args lasercylinder4)
		("link_l" args flashlight_sf)
		("link_l" args peq10)
		("link_l" args peq15)
		("link_l" args laser1mw)
		("link_l" args laser5mw)
		("link_l" args tactical_laser)
		("link_l" args tactical_laser2)
		("link_l" args zenitco)
		("link_l" args liner)
	}
}
{"random_detail"
	{on spawn
		(define "check_upgrade_up_laser" ;Проверка тега при спавне на лазер
			{if tagged "attach_up"
				{if tagged "laser_on_up_%0"
					;{tags remove "laser_off_up"}
					{add_view "laser_sight_add_%0"				"fx_laser_set_up_%0"		"foresight3"}
					{add_view "laser_sight_%0"					"fx_laser_set_up_%0"		"fx_laser_set_up_%0"}
					;{tags add "laser_on_up"}
					;{tags add "laser_on_up_%0"}
					{delay 2
						{if tagged "laser_on_up_peq15"
							{ani_play "caps_laser_up" 0.1}
						}
						{if tagged "laser_on_up_peq10"
							{ani_play "caps_front_up" 0.1}
						}
						{view show	"fx_laser_set_up_%0"}
						{view start	"fx_laser_set_up_%0"}
					}
				}
			}
			{if not sunlight ;Ранд лазер ночью
				{if not user_control	
					{if not tagged "laser_on_up"
						{if tagged "attach_up_%0"
							{if rand 0.3
								{delay 3 1
									{tags remove "laser_off_up"}
									{tags add "laser_on_up"}
									{tags add "laser_on_up_%0"}
									{ani_play "caps_light_up" 0.1}
									{delay 0.5
										{add_view "laser_sight_add_%0"				"fx_laser_set_up_%0"		"foresight3"}
										{add_view "laser_sight_%0"					"fx_laser_set_up_%0"		"fx_laser_set_up_%0"}
										{tags remove "light_off_up"}
										{tags add "laser_on_up"}
										{tags add "laser_on_up_%0"}
										{delay 2
											{view show	"fx_laser_set_up_%0"}
											{view start	"fx_laser_set_up_%0"}
										}
										{start_sound "weapon/equip/"}
									}
								}
							}
						}
					}
				}
			}
		)
		("check_upgrade_up_laser" args peq10)
		("check_upgrade_up_laser" args peq15)
		("check_upgrade_up_laser" args laser1mw)
		("check_upgrade_up_laser" args laser5mw)
		("check_upgrade_up_laser" args tactical_laser)
		("check_upgrade_up_laser" args tactical_laser2)
		("check_upgrade_up_laser" args zenitco)
		("check_upgrade_up_laser" args liner)
		("check_upgrade_up_laser" args lasercylinder1)
		("check_upgrade_up_laser" args lasercylinder3)
		("check_upgrade_up_laser" args lasercylinder4)
		(define "check_upgrade_up_light" ;Проверка тега при спавне на свет
			{if tagged "attach_up"
				{if tagged "light_on_up_%0"
					{delay 0.5
						{add_view "headlight_weapon3"		"fx_light_set_up_%0"		"fx_light_set_up_%0"}		
						{delay 2
							{if tagged "attach_up_peq15"
								{ani_play "caps_light_up" 0.1}
							}
							{if tagged "attach_up_peq10"
								{ani_play "caps_front_up" 0.1}
							}
							{view show	"fx_light_set_up_%0"}
							{view start	"fx_light_set_up_%0"}
						}
					}
				}
			}
		)
		("check_upgrade_up_light" args flashlight_sf)
		("check_upgrade_up_light" args peq10)
		("check_upgrade_up_light" args peq15)
		("check_upgrade_up_light" args laser1mw)
		("check_upgrade_up_light" args laser5mw)
		("check_upgrade_up_light" args zenitco)
		(define "check_upgrade_l_laser" ;Проверка тега при спавне на лазер
			{if tagged "attach_l"
				{if tagged "laser_on_l_%0"
					;{tags remove "laser_off_l"}
					{add_view "laser_sight_add_%0"				"fx_laser_set_l_%0"		"foresight3"}
					{add_view "laser_sight_%0"					"fx_laser_set_l_%0"		"fx_laser_set_l_%0"}
					;{tags add "laser_on_l"}
					;{tags add "laser_on_l_%0"}
					{delay 2
						{if tagged "laser_on_l_peq15"
							{ani_play "caps_laser_l" 0.1}
						}
						{if tagged "laser_on_l_peq10"
							{ani_play "caps_front_l" 0.1}
						}
						{view show	"fx_laser_set_l_%0"}
						{view start	"fx_laser_set_l_%0"}
					}
				}
			}
			{if not sunlight ;Ранд лазер ночью
				{if not user_control	
					{if not tagged "laser_on_l"
						{if tagged "attach_l_%0"
							{if rand 0.3
								{delay 3 1
									{tags remove "laser_off_l"}
									{tags add "laser_on_l"}
									{tags add "laser_on_l_%0"}
									{ani_play "caps_light_l" 0.1}
									{delay 0.5
										{add_view "laser_sight_add_%0"				"fx_laser_set_l_%0"		"foresight3"}
										{add_view "laser_sight_%0"					"fx_laser_set_l_%0"		"fx_laser_set_l_%0"}
										{tags remove "light_off_l"}
										{tags add "laser_on_l"}
										{tags add "laser_on_l_%0"}
										{delay 2
											{view show	"fx_laser_set_l_%0"}
											{view start	"fx_laser_set_l_%0"}
										}
										{start_sound "weapon/equip/"}
									}
								}
							}
						}
					}
				}
			}
		)
		("check_upgrade_l_laser" args peq10)
		("check_upgrade_l_laser" args peq15)
		("check_upgrade_l_laser" args laser1mw)
		("check_upgrade_l_laser" args laser5mw)
		("check_upgrade_l_laser" args tactical_laser)
		("check_upgrade_l_laser" args tactical_laser2)
		("check_upgrade_l_laser" args zenitco)
		("check_upgrade_l_laser" args liner)
		("check_upgrade_l_laser" args lasercylinder1)
		("check_upgrade_l_laser" args lasercylinder3)
		("check_upgrade_l_laser" args lasercylinder4)
		(define "check_upgrade_l_light" ;Проверка тега при спавне на свет
			{if tagged "attach_l"
				{if tagged "light_on_l_%0"
					{delay 0.5
						{add_view "headlight_weapon3"		"fx_light_set_l_%0"		"fx_light_set_l_%0"}		
						;{tags remove "light_off_l"}
						;{tags add "light_on_l"}
						;{tags add "light_on_l_%0"}
						{delay 2
							{if tagged "attach_l_peq15"
								{ani_play "caps_light_l" 0.1}
							}
							{if tagged "attach_l_peq10"
								{ani_play "caps_front_l" 0.1}
							}
							{view show	"fx_light_set_l_%0"}
							{view start	"fx_light_set_l_%0"}
						}
					}
				}
			}
		)
		("check_upgrade_l_light" args flashlight_sf)
		("check_upgrade_l_light" args peq10)
		("check_upgrade_l_light" args peq15)
		("check_upgrade_l_light" args laser1mw)
		("check_upgrade_l_light" args laser5mw)
		("check_upgrade_l_light" args zenitco)
		(define "check_upgrade_r_light";Проверка тега при спавне на свет
			{if tagged "attach_r"
				{if tagged "light_on_r_%0"
					{delay 0.5
						{add_view "headlight_weapon3"		"fx_light_set_r_%0"		"fx_light_set_r_%0"}		
						;{tags remove "light_off_r"}
						;{tags add "light_on_r"}
						;{tags add "light_on_r_%0"}
						{delay 2
							{if tagged "attach_r_peq15"
								{ani_play "caps_light_r" 0.1}
							}
							{if tagged "attach_r_peq10"
								{ani_play "caps_front_r" 0.1}
							}
							{view show	"fx_light_set_r_%0"}
							{view start	"fx_light_set_r_%0"}
						}
					}
				}
			}
		)
		("check_upgrade_r_light" args flashlight_sf)
		("check_upgrade_r_light" args peq10)
		("check_upgrade_r_light" args peq15)
		("check_upgrade_r_light" args laser1mw)
		("check_upgrade_r_light" args laser5mw)
		("check_upgrade_r_light" args zenitco)
		(define "check_upgrade_r_laser" ;Проверка тега при спавне на лазер
			{if tagged "attach_r"
				{if tagged "laser_on_r_%0"
					{add_view "laser_sight_add_%0"				"fx_laser_set_r_%0"		"foresight3"}
					{add_view "laser_sight_%0"					"fx_laser_set_r_%0"		"fx_laser_set_r_%0"}
					;{tags remove "laser_off_r"}
					;{tags add "laser_on_r"}
					;{tags add "laser_on_r_%0"}
					{delay 2
						{if tagged "laser_on_r_peq15"
							{ani_play "caps_laser_r" 0.1}
						}
						{if tagged "laser_on_r_peq10"
							{ani_play "caps_front_r" 0.1}
						}
						{view show	"fx_laser_set_r_%0"}
						{view start	"fx_laser_set_r_%0"}
					}
				}
			}
			{if not sunlight
				{if not user_control	
					{if not tagged "laser_on_r"
						{if rand 0.3
							{if tagged "attach_r_%0"
								{delay 3 1
									{tags remove "laser_off_r"}
									{tags add "laser_on_r"}
									{tags add "laser_on_r_%0"}
									{ani_play "caps_laser_r" 0.1}
									{delay 0.5
										{add_view "laser_sight_add_%0"				"fx_laser_set_r_%0"		"foresight3"}
										{add_view "laser_sight_%0"					"fx_laser_set_r_%0"		"fx_laser_set_r_%0"}
										{tags remove "light_off_r"}
										{tags add "laser_on_r"}
										{tags add "laser_on_r_%0"}
										{delay 2
											{view show	"fx_laser_set_r_%0"}
											{view start	"fx_laser_set_r_%0"}
										}
										{start_sound "weapon/equip/"}
									}
								}
							}
						}
					}
				}
			}
		)
		("check_upgrade_r_laser" args peq10)
		("check_upgrade_r_laser" args peq15)
		("check_upgrade_r_laser" args laser1mw)
		("check_upgrade_r_laser" args laser5mw)
		("check_upgrade_r_laser" args tactical_laser)
		("check_upgrade_r_laser" args tactical_laser2)
		("check_upgrade_r_laser" args zenitco)
		("check_upgrade_r_laser" args lasercylinder1)
		("check_upgrade_r_laser" args lasercylinder3)
		("check_upgrade_r_laser" args lasercylinder4)
		(define "check_upgrade_l"
			{if not tagged "attach_l_%0" 
				{volumes "attach_l" enable touch select}
				{bone hide "upgrade_left_%0"}
				{volumes "body_s_l_%0" disable contact_ground contact obstacle blast bullet overlap}
			}
			{if tagged "attach_l_%0" 
				{tags remove "detach_l"}
				{tags add "attach_l"}
				{tags add "attach_l_%0"}
				{volumes "body_s_l_%0" enable contact_ground contact obstacle blast bullet overlap}
				{bone hide	"%0_l_ui"}
				{bone hide	"%0_l_light_on_ui"}
				{bone hide	"%0_l_laser_on_ui"}
				{volumes "attach_l" disable touch select}
				{volumes "%0_l_light_on_ui" disable touch}
				{volumes "%0_l_laser_on_ui" disable touch}
				{ani_play "%0_l_ui" -0.1}
				{bone show "upgrade_left_%0"}
			}
		)
		("check_upgrade_l" args peq10)
		("check_upgrade_l" args peq15)
		("check_upgrade_l" args flashlight_sf)
		("check_upgrade_l" args laser1mw)
		("check_upgrade_l" args laser5mw)
		("check_upgrade_l" args tactical_laser)
		("check_upgrade_l" args tactical_laser2)
		("check_upgrade_l" args zenitco)
		("check_upgrade_l" args liner)
		("check_upgrade_l" args lasercylinder1)
		("check_upgrade_l" args lasercylinder3)
		("check_upgrade_l" args lasercylinder4)
		(define "check_upgrade_r"
			{if not tagged "attach_r_%0" 
				{volumes "attach_r" enable touch select}
				{bone hide "upgrade_right_%0"}
				{volumes "body_s_r_%0" disable contact_ground contact obstacle blast bullet overlap}
			}
			{if tagged "attach_r_%0" 
				{tags remove "detach_r"}
				{tags add "attach_r"}
				{tags add "attach_r_%0"}
				{volumes "attach_r" disable touch select}
				{volumes "body_s_r_%0" enable contact_ground contact obstacle blast bullet overlap}
				{bone hide	"%0_r_ui"}
				{bone hide	"%0_r_light_on_ui"}
				{bone hide	"%0_r_laser_on_ui"}
				{volumes "%0_r_light_on_ui" disable touch}
				{volumes "%0_r_laser_on_ui" disable touch}
				{ani_play "%0_r_ui" -0.1}
				{bone show "upgrade_right_%0"}
			}
		)
		("check_upgrade_r" args peq10)
		("check_upgrade_r" args peq15)
		("check_upgrade_r" args flashlight_sf)
		("check_upgrade_r" args laser1mw)
		("check_upgrade_r" args laser5mw)
		("check_upgrade_r" args tactical_laser)
		("check_upgrade_r" args tactical_laser2)
		("check_upgrade_r" args zenitco)
		("check_upgrade_r" args liner)
		("check_upgrade_r" args lasercylinder1)
		("check_upgrade_r" args lasercylinder3)
		("check_upgrade_r" args lasercylinder4)
		(define "check_upgrade_up"
			{if not tagged "attach_up_%0" 
				{volumes "attach_up" enable touch select}
				{bone hide "upgrade_upper_%0"}
				{volumes "body_s_up_%0" disable contact_ground contact obstacle blast bullet overlap}
			}
			{if tagged "attach_up_%0" 
				{volumes "attach_up" disable touch select}
				{tags remove "detach_up"}
				{tags add "attach_up"}
				{tags add "attach_up_%0"}
				{volumes "body_s_up_%0" enable contact_ground contact obstacle blast bullet overlap}
				{bone hide	"%0_up_ui"}
				{bone hide	"%0_up_light_on_ui"}
				{bone hide	"%0_up_laser_on_ui"}
				{volumes "%0_up_light_on_ui" disable touch}
				{volumes "%0_up_laser_on_ui" disable touch}
				{ani_play "%0_up_ui" -0.1}
				{bone show "upgrade_upper_%0"}
			}
		)
		("check_upgrade_up" args peq10)
		("check_upgrade_up" args peq15)
		("check_upgrade_up" args flashlight_sf)
		("check_upgrade_up" args laser1mw)
		("check_upgrade_up" args laser5mw)
		("check_upgrade_up" args tactical_laser)
		("check_upgrade_up" args tactical_laser2)
		("check_upgrade_up" args zenitco)
		("check_upgrade_up" args liner)
		("check_upgrade_up" args lasercylinder1)
		("check_upgrade_up" args lasercylinder3)
		("check_upgrade_up" args lasercylinder4)
		{if prop "attach_light_up" 
			{delay 0.2
				{if not tagged "attach_all" 
					{if rand 0.2
						{tags add "attach_up_tactical_laser2"}
						{tags add "attach_up"}
						{tags add "attach_all"}
						{tags remove "detach_up"}
						{volumes "body_s_up_tactical_laser2" enable contact_ground contact obstacle blast bullet overlap}
						{bone hide	"front_sight"}
						{bone hide	"tactical_laser2_up_ui"}
						{bone hide	"tactical_laser2_up_light_on_ui"}
						{bone hide	"ftactical_laser2_up_laser_on_ui"}
						{volumes "tactical_laser2_up_light_on_ui" disable touch}
						{volumes "tactical_laser2_up_laser_on_ui" disable touch}
						{bone show "upgrade_upper_tactical_laser2"}
						{if not sunlight
							{if not user_control	
								{tags remove "laser_off_up"}
								{tags add "laser_on_up"}
								{tags add "laser_on_up_tactical_laser2"}
								{add_view "laser_sight_tactical_laser2"		"fx_light_set_up_tactical_laser2"		"fx_light_set_up_tactical_laser2"}		
								{delay 1
									{view show	"fx_light_set_up_tactical_laser2"}
									{view start	"fx_light_set_up_tactical_laser2"}
								}
							}
						}
					}
;				else rand 0.05 ;рандом на liner
				else
					{if not tagged "attach_up" 
						{delay 0.1
							{volumes "attach_up" enable touch select}
							{bone show	"front_sight"}
							{tags add "detach_up"}
						}
					}
				}
			}
		}
		{if prop "attach_light_l" 
			{if not tagged "attach_all" 
				{delay 0.2
					{if rand 0.2
						{tags add "attach_l_flashlight_sf"}
						{tags add "attach_l"}
						{tags add "attach_all"}
						{tags remove "detach_l"}
						{volumes "body_s_l_flashlight_sf" enable contact_ground contact obstacle blast bullet overlap}
						{bone hide	"flashlight_sf_l_ui"}
						{bone hide	"flashlight_sf_l_light_on_ui"}
						{bone hide	"flashlight_sf_l_laser_on_ui"}
						{volumes "flashlight_sf_l_light_on_ui" disable touch}
						{volumes "flashlight_sf_l_laser_on_ui" disable touch}
						{bone show "upgrade_left_flashlight_sf"}
						{if not sunlight
							{if not user_control	
								{tags remove "light_off_l"}
								{tags add "light_on_l"}
								{tags add "light_on_l_flashlight_sf"}
								{add_view "headlight_weapon_flashlight_sf"		"fx_light_set_l_flashlight_sf"		"fx_light_set_l_flashlight_sf"}		
								{delay 1
									;{view show	"fx_light_set_l_flashlight_sf"}
									{view start	"fx_light_set_l_flashlight_sf"}
								}
							}
						}
					else rand 0.05 ;рандом на liner
						{tags add "attach_r_liner"}
						{tags add "attach_r"}
						{tags remove "detach_r"}
						{volumes "body_s_r_liner" enable contact_ground contact obstacle blast bullet overlap}
						{bone hide	"liner_r_ui"}
						{bone hide	"liner_r_light_on_ui"}
						{bone hide	"liner_r_laser_on_ui"}
						{volumes "liner_r_light_on_ui" disable touch}
						{volumes "liner_r_laser_on_ui" disable touch}
						{bone show "upgrade_right_liner"}
						{if not sunlight
							{if not user_control	
								{delay 3 1
									{tags remove "laser_off_r"}
									{tags add "laser_on_r"}
									{tags add "laser_on_r_liner"}
									{delay 0.5
										{add_view "laser_sight_add_liner"			"fx_laser_set_r_liner"		"foresight3"}
										{add_view "laser_sight_liner"					"fx_laser_set_r_liner"		"fx_laser_set_r_liner"}
										{tags remove "light_off_r"}
										{tags add "laser_on_r"}
										{tags add "laser_on_r_liner"}
										{delay 2
											{start_sound "weapon/equip/"}
											{view show	"fx_laser_set_r_liner"}
											{view start	"fx_laser_set_r_liner"}
										}
									}
								}
							}
						}
					else
						{if not tagged "attach_l" 
							{delay 0.1
								{volumes "attach_l" enable touch select}
								{tags add "detach_l"}
							}
						}
					}
				}
			}
		}
	}	
}

{"random_detail_small"
	{on spawn
		(define "check_upgrade_d"
			{if not tagged "attach_d_%0" 
				{volumes "attach_d" enable touch select }
				{bone hide "upgrade_down_%0"}
				{volumes "body_s_d_%0" disable contact_ground contact obstacle blast bullet overlap}
			}
			{if tagged "attach_d_%0" 
				{volumes "attach_d" disable touch select }
				{tags remove "detach_d"}
				{tags add "attach_d"}
				{tags add "attach_d_%0"}
				{volumes "body_s_d_%0" enable contact_ground contact obstacle blast bullet overlap}
				{bone show "upgrade_down_%0"}
			}
		)		
		("check_upgrade_d" args laser5mw)
		("check_upgrade_d" args tactical_laser)
		("check_upgrade_d" args zenitco)
		("check_upgrade_d" args tlr2)
		("check_upgrade_d" args sfx300)
		{delay 0.2
			{if rand 0.2
				{tags add "attach_d_sfx300"}
				{tags add "attach_d"}
				{tags remove "detach_d"}
				{volumes "body_s_l_sfx300" enable contact_ground contact obstacle blast bullet overlap}
				{bone show "upgrade_down_sfx300"}
				{if not sunlight
					{if not user_control	
						{tags remove "light_off_d"}
						{tags add "light_on_d"}
						{tags add "light_on_d_sfx300"}
						{add_view "headlight_weapon_sfx300"		"fx_light_set_sfx300"		"fx_light_set_sfx300"}		
						{delay 1
							{view start	"fx_light_set_sfx300"}
						}
					}
				}
			else rand 0.05 ;рандом на tactical_laser
				{tags add "attach_d_tactical_laser"}
				{tags add "attach_d"}
				{tags remove "detach_d"}
				{volumes "body_s_d_tactical_laser" enable contact_ground contact obstacle blast bullet overlap}
				{bone show "upgrade_down_tactical_laser"}
				{if not sunlight
					{if not user_control	
						{delay 3 1
							{tags remove "laser_off_d"}
							{tags add "laser_on_d"}
							{tags add "laser_on_d_liner"}
							{delay 0.5
								{add_view "laser_sight_add_tactical_laser"				"fx_laser_set_tactical_laser"		"foresight3"}
								{add_view "laser_sight_tactical_laser"					"fx_laser_set_tactical_laser"		"fx_laser_set_tactical_laser"}
								{tags remove "light_off_d"}
								{tags add "laser_on_d"}
								{tags add "laser_on_d_liner"}
								{delay 2
									{start_sound "weapon/equip/"}
									{view show	"fx_laser_set_d_liner"}
									{view start	"fx_laser_set_d_liner"}
								}
							}
						}
					}
				}
			else
				{if not tagged "attach_d" 
					{delay 0.1
						{tags add "detach_d"}
					}
				}
			}
		}
	}	
}
;----------------------single
{"update_lasers"
	{on spawn
		{if not tagged "laser_on" 
			{tags add "laser_off"}
		}
	}
	{on "open_laser"
		{if tagged "laser_off" 
			{tags remove "laser_off"}
			{tags add "laser_on"}
			{ani_play "caps_laser" 0.1}
			{ani_play "caps_front" 0.1}
			{delay 0.5
				(define "open_laser"
					{tags add "laser_on_%0"}
					{add_view "laser_sight_add_%0"				"fx_laser_set_%0"		"fx_laser_set_%0"}
					{add_view "laser_sight_%0"					"fx_laser_set_%0"		"fx_laser_set_%0"}
					{view start	"fx_laser_set_%0"}
					{start_sound "weapon/equip/"}
				)
				("open_laser" args peq10)
				("open_laser" args peq15)
				("open_laser" args laser1mw)
				("open_laser" args laser5mw)
				("open_laser" args tactical_laser)
				("open_laser" args tactical_laser2)
				("open_laser" args zenitco)
				("open_laser" args liner)
				("open_laser" args lasercylinder1)
				("open_laser" args lasercylinder3)
				("open_laser" args lasercylinder4)
			}
		else 
			{delay 0.5
				(define "open_laser"
					{start_sound "weapon/equip/"}
					{tags add "laser_off"}
					{tags remove "laser_on_%0"}
					{tags remove "laser_on"}
					{ani_play "caps_laser" -0.2}
					{ani_play "caps_front" -0.2}
					{view stop	"fx_laser_set_%0"}
					{view hide	"fx_laser_set_%0"}
				)
				("open_laser" args peq10)
				("open_laser" args peq15)
				("open_laser" args laser1mw)
				("open_laser" args laser5mw)
				("open_laser" args tactical_laser)
				("open_laser" args tactical_laser2)
				("open_laser" args zenitco)
				("open_laser" args liner)
				("open_laser" args lasercylinder1)
				("open_laser" args lasercylinder3)
				("open_laser" args lasercylinder4)
			}
		}
	}
}

{"update_lights"
	{on spawn
		{if not tagged "light_on" 
			{tags add "light_off"}
			(define "set_light"
				{view hide	"fx_light_set_%0"}
				{view stop	"fx_light_set_%0"}
			)
			("set_light" args flashlight_sf)
			("set_light" args peq10)
			("set_light" args peq15)
			("set_light" args laser1mw)
			("set_light" args laser5mw)
			("set_light" args zenitco)
		}
	}
	{on "open_light"
		{if tagged "light_off" 
			{tags remove "light_off"}
			{tags add "light_on"}
			{ani_play "caps_light" 0.1}
			{ani_play "caps_front" 0.1}
			{delay 0.5
				(define "open_light"
					{add_view "headlight_weapon_%0"		"fx_light_set_%0"		"fx_light_set_%0"}		
					{tags add "light_on_%0"}
					{view start	"fx_light_set_%0"}
					{view show	"fx_light_set_%0"}
					{start_sound "weapon/equip/"}
				)
				("open_light" args flashlight_sf)
				("open_light" args peq10)
				("open_light" args peq15)
				("open_light" args laser1mw)
				("open_light" args laser5mw)
				("open_light" args zenitco)
			}
		else 
			{delay 0.5
				(define "open_light"
					{start_sound "weapon/equip/"}
					{tags remove "light_on"}
					{ani_play "caps_light" -0.2}
					{tags add "light_off"}
					{tags remove "light_on_%0"}
					{view stop	"fx_light_set_%0"}
					{view hide	"fx_light_set_%0"}
				)
				("open_light" args flashlight_sf)
				("open_light" args peq10)
				("open_light" args peq15)
				("open_light" args laser1mw)
				("open_light" args laser5mw)
				("open_light" args zenitco)
			}
		}
	}
}

;----------------------------------------------------------------------------------------------------------------------------

{"update_lasers_up"
	{on spawn
		{if not tagged "laser_on_up"
			{tags add "laser_off_up"}
		}
	}
	{on "open_laser_up"
		{if tagged "laser_off_up"
			{tags remove "laser_off_up"}
			{tags add "laser_on_up"}
			{ani_play "caps_laser_up"0.1}
			{ani_play "caps_front_up"0.1}
			{delay 0.5
				(define "open_laser_up"
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{delay 0.1 
						{tex_mod "laser_up_on"}
					}
					{start_sound "weapon/equip/"}
					{if tagged "attach_up_%0"
						{add_view "laser_sight_add_%0"				"fx_laser_set_up_%0"		"fx_laser_set_up_%0"}
						{add_view "laser_sight_%0"					"fx_laser_set_up_%0"		"fx_laser_set_up_%0"}
						{tags add "laser_on_up_%0"}
						{view start	"fx_laser_set_up_%0"}
					}
				)
				("open_laser_up"args peq10)
				("open_laser_up"args peq15)
				("open_laser_up"args laser1mw)
				("open_laser_up"args laser5mw)
				("open_laser_up"args tactical_laser)
				("open_laser_up"args tactical_laser2)
				("open_laser_up"args zenitco)
				("open_laser_up"args liner)
				("open_laser_up"args lasercylinder1)
				("open_laser_up"args lasercylinder3)
				("open_laser_up"args lasercylinder4)
			}
		else 
			{delay 0.5
				(define "open_laser_up"
					{if tagged "attach_up_%0"
						{tags add "laser_off_up"}
						("check_tex" skin(1) )					
						("check_tex" skin(2) )					
						("check_tex" skin(3) )					
						("check_tex" skin(4) )					
						("check_tex" skin(5) )					
						("check_tex" skin(6) )					
						("check_tex" skin(7) )					
						("check_tex" skin(8) )					
						("check_tex" skin(9) )					
						("check_tex" skin(10) )					
						("check_tex" skin(d) )					
						("check_tex" skin(w) )					
						("check_tex" skin(s) )					
						{delay 0.1 
							{tex_mod "laser_up_off"}
						}
						{start_sound "weapon/equip/"}
						{tags remove "laser_on_up"}
						{tags remove "laser_on_up_%0"}
						{ani_play "caps_laser_up"-0.2}
						{ani_play "caps_front_up"-0.2}
						{view stop	"fx_laser_set_up_%0"}
						{view hide	"fx_laser_set_up_%0"}
					}
				)
				("open_laser_up"args peq10)
				("open_laser_up"args peq15)
				("open_laser_up"args laser1mw)
				("open_laser_up"args laser5mw)
				("open_laser_up"args tactical_laser)
				("open_laser_up"args tactical_laser2)
				("open_laser_up"args zenitco)
				("open_laser_up"args liner)
				("open_laser_up"args lasercylinder1)
				("open_laser_up"args lasercylinder3)
				("open_laser_up"args lasercylinder4)
			}
		}
	}
}

{"update_lights_up"
	{on spawn
		{if not tagged "light_on_up"
			{tags add "light_off_up"}
		}
		(define "set_light_up"
			{view hide	"fx_light_set_up_%0"}
			{view stop	"fx_light_set_up_%0"}
		)
		("set_light_up"args flashlight_sf)
		("set_light_up"args peq10)
		("set_light_up"args peq15)
		("set_light_up"args laser1mw)
		("set_light_up"args laser5mw)
		("set_light_up"args zenitco)
	}
	{on "open_light_up"
		{if tagged "light_off_up"
			{tags remove "light_off_up"}
			{tags add "light_on_up"}
			{ani_play "caps_light_up"0.1}
			{ani_play "caps_front_up"0.1}
			{delay 0.5
				(define "open_light_up"
					{delay 0.1 
						{tex_mod "light_up_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{if tagged "attach_up_%0"
						{add_view "headlight_weapon_%0"		"fx_light_set_up_%0"		"fx_light_set_up_%0"}		
						{tags add "light_on_up_%0"}
					}
					{view show	"fx_light_set_up_%0"}
					{view start	"fx_light_set_up_%0"}
				)
				("open_light_up"args flashlight_sf)
				("open_light_up"args peq10)
				("open_light_up"args peq15)
				("open_light_up"args laser1mw)
				("open_light_up"args laser5mw)
				("open_light_up"args zenitco)
			}
		else 
			{delay 0.5
				(define "open_light_up"
					{delay 0.1 
						{tex_mod "light_up_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{tags remove "light_on_up"}
					{ani_play "caps_light_up"-0.2}
					{ani_play "caps_front_up"-0.2}
					{tags add "light_off_up"}
					{tags remove "light_on_up_%0"}
					{view hide	"fx_light_set_up_%0"}
					{view stop	"fx_light_set_up_%0"}
				)
				("open_light_up"args flashlight_sf)
				("open_light_up"args peq10)
				("open_light_up"args peq15)
				("open_light_up"args laser1mw)
				("open_light_up"args laser5mw)
				("open_light_up"args zenitco)
			}
		}
	}
}



{"update_lasers_r"
	{on spawn
		{if not tagged "laser_on_r" 
			{tags add "laser_off_r"}
		}
	}
	{on "open_laser_r"
		{if tagged "laser_off_r" 
			{tags remove "laser_off_r"}
			{tags add "laser_on_r"}
			{ani_play "caps_laser_r" 0.1}
			{ani_play "caps_front_r" 0.1}
			{delay 0.5
				(define "open_laser_r"
					{delay 0.1 
						{tex_mod "laser_r_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{if tagged "attach_r_%0"
						{add_view "laser_sight_add_%0"				"fx_laser_set_r_%0"		"fx_laser_set_r_%0"}
						{add_view "laser_sight_%0"					"fx_laser_set_r_%0"		"fx_laser_set_r_%0"}
						{tags add "laser_on_r_%0"}
						{view start	"fx_laser_set_r_%0"}
						;{view show	"fx_laser_set_r_%0"}
					}
				)
				("open_laser_r" args peq10)
				("open_laser_r" args peq15)
				("open_laser_r" args laser1mw)
				("open_laser_r" args laser5mw)
				("open_laser_r" args tactical_laser)
				("open_laser_r" args tactical_laser2)
				("open_laser_r" args zenitco)
				("open_laser_r" args liner)
				("open_laser_r" args lasercylinder1)
				("open_laser_r" args lasercylinder3)
				("open_laser_r" args lasercylinder4)
			}
		else 
			{delay 0.5
				(define "open_laser_r"
					{if tagged "attach_r_%0"
						{tags add "laser_off_r"}
						{delay 0.1 
							{tex_mod "laser_r_off"}
						}
						("check_tex" skin(1) )					
						("check_tex" skin(2) )					
						("check_tex" skin(3) )					
						("check_tex" skin(4) )					
						("check_tex" skin(5) )					
						("check_tex" skin(6) )					
						("check_tex" skin(7) )					
						("check_tex" skin(8) )					
						("check_tex" skin(9) )					
						("check_tex" skin(10) )					
						("check_tex" skin(d) )					
						("check_tex" skin(w) )					
						("check_tex" skin(s) )					
 
						{start_sound "weapon/equip/"}
						{tags remove "laser_on_r"}
						{tags remove "laser_on_r_%0"}
						{ani_play "caps_laser_r" -0.2}
						{ani_play "caps_front_r" -0.2}
						{view stop	"fx_laser_set_r_%0"}
						{view hide	"fx_laser_set_r_%0"}
					}
				)
				("open_laser_r" args peq10)
				("open_laser_r" args peq15)
				("open_laser_r" args laser1mw)
				("open_laser_r" args laser5mw)
				("open_laser_r" args tactical_laser)
				("open_laser_r" args tactical_laser2)
				("open_laser_r" args zenitco)
				("open_laser_r" args liner)
				("open_laser_r" args lasercylinder1)
				("open_laser_r" args lasercylinder3)
				("open_laser_r" args lasercylinder4)
			}
		}
	}
}

{"update_lights_r"
	{on spawn
		{if not tagged "light_on_r" 
			{tags add "light_off_r"}
		}
		(define "set_light_r"
			{view hide	"fx_light_set_r_%0"}
			{view stop	"fx_light_set_r_%0"}
		)
		("set_light_r" args flashlight_sf)
		("set_light_r" args peq10)
		("set_light_r" args peq15)
		("set_light_r" args laser1mw)
		("set_light_r" args laser5mw)
		("set_light_r" args zenitco)
	}
	{on "open_light_r"
		{if tagged "light_off_r" 
			{tags remove "light_off_r"}
			{tags add "light_on_r"}
			{ani_play "caps_light_r" 0.1}
			{ani_play "caps_front_r" 0.1}
			{delay 0.5
				(define "open_light_r"
					{delay 0.1 
						{tex_mod "light_r_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{if tagged "attach_r_%0"
						{add_view "headlight_weapon_%0"		"fx_light_set_r_%0"		"fx_light_set_r_%0"}		
						{tags add "light_on_r_%0"}
					}
					{view show	"fx_light_set_r_%0"}
					{view start	"fx_light_set_r_%0"}
				)
				("open_light_r" args flashlight_sf)
				("open_light_r" args peq10)
				("open_light_r" args peq15)
				("open_light_r" args laser1mw)
				("open_light_r" args laser5mw)
				("open_light_r" args zenitco)
			}
		else 
			{delay 0.5
				(define "open_light_r"
					{delay 0.1 
						{tex_mod "light_r_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{tags remove "light_on_r"}
					{ani_play "caps_light_r" -0.2}
					{tags add "light_off_r"}
					{tags remove "light_on_r_%0"}
					{view hide	"fx_light_set_r_%0"}
					{view stop	"fx_light_set_r_%0"}
				)
				("open_light_r" args flashlight_sf)
				("open_light_r" args peq10)
				("open_light_r" args peq15)
				("open_light_r" args laser1mw)
				("open_light_r" args laser5mw)
				("open_light_r" args zenitco)
			}
		}
	}
}

{"update_lasers_l"
	{on spawn
		{if not tagged "laser_on_l" 
			{tags add "laser_off_l"}
		}
	}
	{on "open_laser_l"
		{if tagged "laser_off_l" 
			{tags remove "laser_off_l"}
			{tags add "laser_on_l"}
			{ani_play "caps_laser_l" 0.1}
			{ani_play "caps_front_l" 0.1}
			{delay 0.5
				(define "open_laser_l"
					{if tagged "attach_l_%0"
						{tags add "laser_on_l_%0"}
						{add_view "laser_sight_add_%0"				"fx_laser_set_l_%0"		"fx_laser_set_l_%0"}
						{add_view "laser_sight_%0"					"fx_laser_set_l_%0"		"fx_laser_set_l_%0"}
						{view start	"fx_laser_set_l_%0"}
						;{view show	"fx_laser_set_l_%0"}
					}
					{delay 0.1 
						{tex_mod "laser_l_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
				)
				("open_laser_l" args peq10)
				("open_laser_l" args peq15)
				("open_laser_l" args laser1mw)
				("open_laser_l" args laser5mw)
				("open_laser_l" args tactical_laser)
				("open_laser_l" args tactical_laser2)
				("open_laser_l" args zenitco)
				("open_laser_l" args liner)
				("open_laser_l" args lasercylinder1)
				("open_laser_l" args lasercylinder3)
				("open_laser_l" args lasercylinder4)
			}
		else 
			{delay 0.5
				(define "open_laser_l"
					{delay 0.1 
						{tex_mod "laser_l_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{tags add "laser_off_l"}
					{tags remove "laser_on_l_%0"}
					{tags remove "laser_on_l"}
					{ani_play "caps_laser_l" -0.2}
					{ani_play "caps_front_l" -0.2}
					{if tagged "attach_l_%0"
						{view stop	"fx_laser_set_l_%0"}
						{view hide	"fx_laser_set_l_%0"}
					}
				)
				("open_laser_l" args peq10)
				("open_laser_l" args peq15)
				("open_laser_l" args laser1mw)
				("open_laser_l" args laser5mw)
				("open_laser_l" args tactical_laser)
				("open_laser_l" args tactical_laser2)
				("open_laser_l" args zenitco)
				("open_laser_l" args liner)
				("open_laser_l" args lasercylinder1)
				("open_laser_l" args lasercylinder3)
				("open_laser_l" args lasercylinder4)
			}
		}
	}
}

{"update_lights_l"
	{on spawn
		{if not tagged "light_on_l" 
			{tags add "light_off_l"}
			(define "set_light_l"
				{view hide	"fx_light_set_l_%0"}
				{view stop	"fx_light_set_l_%0"}
			)
			("set_light_l" args flashlight_sf)
			("set_light_l" args peq10)
			("set_light_l" args peq15)
			("set_light_l" args laser1mw)
			("set_light_l" args laser5mw)
			("set_light_l" args zenitco)
		}
	}
	{on "open_light_l"
		{if tagged "light_off_l" 
			{tags remove "light_off_l"}
			{tags add "light_on_l"}
			{ani_play "caps_light_l" 0.1}
			{ani_play "caps_front_l" 0.1}
			{delay 0.5
				(define "open_light_l"
					{if tagged "attach_l_%0"
						{add_view "headlight_weapon_%0"		"fx_light_set_l_%0"		"fx_light_set_l_%0"}		
						{tags add "light_on_l_%0"}
						{view start	"fx_light_set_l_%0"}
						{view show	"fx_light_set_l_%0"}
					}
					{delay 0.1 
						{tex_mod "light_l_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
				)
				("open_light_l" args flashlight_sf)
				("open_light_l" args peq10)
				("open_light_l" args peq15)
				("open_light_l" args laser1mw)
				("open_light_l" args laser5mw)
				("open_light_l" args zenitco)
			}
		else 
			{delay 0.5
				(define "open_light_l"
					{delay 0.1 
						{tex_mod "light_l_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{tags remove "light_on_l"}
					{ani_play "caps_light_l" -0.2}
					{tags add "light_off_l"}
					{tags remove "light_on_l_%0"}
					{view stop	"fx_light_set_l_%0"}
					{view hide	"fx_light_set_l_%0"}
				)
				("open_light_l" args flashlight_sf)
				("open_light_l" args peq10)
				("open_light_l" args peq15)
				("open_light_l" args laser1mw)
				("open_light_l" args laser5mw)
				("open_light_l" args zenitco)
			}
		}
	}
}

{"update_lasers"
	{on spawn
		{if not tagged "laser_on_d" 
			{tags add "laser_off_d"}
			(define "set_laser_d"
				{view hide	"fx_laser_set_d_%0"}
				{view stop	"fx_laser_set_d_%0"}
			)
			("set_laser_d" args tlr2)
			("set_laser_d" args sfx300)
			("set_laser_d" args zenitco)
		}
	}
	{on "open_laser"
		{if tagged "laser_off_d" 
			{tags remove "laser_off_d"}
			{tags add "laser_on_d"}
			{ani_play "caps_laser_d" 0.1}
			{ani_play "caps_front_d" 0.1}
			{delay 0.5
				(define "open_laser_d"
					{if tagged "attach_d_%0"
						{tags add "laser_on_d_%0"}
						{add_view "laser_sight_add_%0"				"fx_laser_set_d_%0"		"fx_laser_set_d_%0"}
						{add_view "laser_sight_%0"					"fx_laser_set_d_%0"		"fx_laser_set_d_%0"}
						{view start	"fx_laser_set_d_%0"}
						;{view show	"fx_laser_set_d_%0"}
					}
					{delay 0.1 
						{tex_mod "laser_d_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
				)
				("open_laser_d" args tactical_laser)
				("open_laser_d" args zenitco)
				("open_laser_d" args sfx300)
				("open_laser_d" args tlr2)
				;("open_laser_d" args ---)
			}
		else 
			{delay 0.5
				(define "open_laser_d"
					{delay 0.1 
						{tex_mod "laser_d_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{tags add "laser_off_d"}
					{tags remove "laser_on_d_%0"}
					{tags remove "laser_on_d"}
					{ani_play "caps_laser_d" -0.2}
					{ani_play "caps_front_d" -0.2}
					{if tagged "attach_d_%0"
						{view stop	"fx_laser_set_d_%0"}
						{view hide	"fx_laser_set_d_%0"}
					}
				)
				("open_laser_d" args tactical_laser)
				("open_laser_d" args zenitco)
				("open_laser_d" args sfx300)
				("open_laser_d" args tlr2)
			}
		}
	}
}

{"update_lights"
	{on spawn
		{if not tagged "light_on_d" 
			{tags add "light_off_d"}
			(define "set_light_d"
				{view hide	"fx_light_set_d_%0"}
				{view stop	"fx_light_set_d_%0"}
			)
			("set_light_d" args tlr2)
			("set_light_d" args sfx300)
			("set_light_d" args zenitco)
		}
	}
	{on "open_light"
		{if tagged "light_off_d" 
			{tags remove "light_off_d"}
			{tags add "light_on_d"}
			{ani_play "caps_light_d" 0.1}
			{ani_play "caps_front_d" 0.1}
			{delay 0.5
				(define "open_light_d"
					{if tagged "attach_d_%0"
						{add_view "headlight_weapon_%0"		"fx_light_set_d_%0"		"fx_light_set_d_%0"}		
						{tags add "light_on_d_%0"}
						{view start	"fx_light_set_d_%0"}
						{view show	"fx_light_set_d_%0"}
					}
					{delay 0.1 
						{tex_mod "light_d_on"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
				)
				("open_light_d" args zenitco)
				("open_light_d" args tlr2)
				("open_light_d" args sfx300)
			}
		else 
			{delay 0.5
				(define "open_light_d"
					{delay 0.1 
						{tex_mod "light_d_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{start_sound "weapon/equip/"}
					{tags remove "light_on_d"}
					{ani_play "caps_light_d" -0.2}
					{tags add "light_off_d"}
					{tags remove "light_on_d_%0"}
					{view stop	"fx_light_set_d_%0"}
					{view hide	"fx_light_set_d_%0"}
				)
				("open_light_d" args zenitco)
				("open_light_d" args tlr2)
				("open_light_d" args sfx300)
			}
		}
	}
}

{"rotate"
	{on "rotate_gun"
		{if not tagged "rotate"
			{start_sound "weapon/equip/"}
			{tags add "rotate"}
			{ani_play "upgrade" 3}
		else 
			{start_sound "weapon/equip/"}
			{tags remove "rotate"}
			{ani_play "upgrade" -3}
		}
	}
}

{"detach_light_up"
	{on spawn
		{tags add "detach_up"}
	}
	(define "upgrade_up"
		{on "detach_light_up_%0"
			{if tagged "attach_up_%0" 
				{delay 0.5
					{volumes "attach_up" enable touch select}
					{bone show	"front_sight"}
					{delay 0.1 
						{tex_mod "laser_up_off"}
						{tex_mod "light_up_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{tags remove "laser_on_up_%0"}
					{tags remove "light_on_up_%0"}
					{ani_play "caps_laser_up" -0.2}
					{ani_play "caps_front_up" -0.2}
					{start_sound "weapon/detach/"}
					{tags add "detach_up"}
					{tags remove "attach_up_%0"}
					{tags remove "light_on_up"}
					{tags remove "laser_on_up"}
					{tags remove "light_on_up_%0"}
					{tags remove "laser_on_up_%0"}
					{tags remove "attach_up"}
					{view stop	"fx_light_set_up_%0"}
					{view hide	"fx_light_set_up_%0"}
					{view stop	"fx_laser_set_up_%0"}
					{view hide	"fx_laser_set_up_%0"}
					{bone hide "upgrade_upper_%0"}
					{volumes "body_s_up_%0" disable contact_ground contact obstacle blast bullet overlap}
					{spawn "%0" "upgrade_upper_%0" {impulse up 0.1}}
				}
			}
		}
	)
	("upgrade_up" args peq10)
	("upgrade_up" args peq15)
	("upgrade_up" args flashlight_sf)
	("upgrade_up" args laser1mw)
	("upgrade_up" args laser5mw)
	("upgrade_up" args tactical_laser)
	("upgrade_up" args tactical_laser2)
	("upgrade_up" args zenitco)
	("upgrade_up" args liner)
	("upgrade_up" args lasercylinder1)
	("upgrade_up" args lasercylinder3)
	("upgrade_up" args lasercylinder4)
}
{"attach_light_up"
	{on spawn
		(define "spawn_upgrade_up"
			{volumes "%0_up_light_on_ui" disable contact_ground contact obstacle blast bullet overlap}
			{volumes "%0_up_laser_on_ui" disable contact_ground contact obstacle blast bullet overlap}
			{if not tagged "attach_up" 
				{bone hide	"upgrade_upper_%0"}
			}
		)
		("spawn_upgrade_up" args peq10)
		("spawn_upgrade_up" args peq15)
		("spawn_upgrade_up" args flashlight_sf)
		("spawn_upgrade_up" args laser1mw)
		("spawn_upgrade_up" args laser5mw)
		("spawn_upgrade_up" args tactical_laser)
		("spawn_upgrade_up" args tactical_laser2)
		("spawn_upgrade_up" args zenitco)
		("spawn_upgrade_up" args liner)
		("spawn_upgrade_up" args lasercylinder1)
		("spawn_upgrade_up" args lasercylinder3)
		("spawn_upgrade_up" args lasercylinder4)
	}
	(define "upgrade_up"
		{on "attach_light_up_%0"
			{if tagged "detach_up" 
				{delay 0.5
					{volumes "attach_up" disable touch select}
					{start_sound "weapon/attach/"}
					{tags remove "detach_up"}
					{tags add "attach_up_%0"}
					{tags add "attach_up"}
					{bone hide	"front_sight"}					
					{bone show	"%0_up_ui"}
					{bone show	"%0_up_light_on_ui"}
					{bone show	"%0_up_laser_on_ui"}
					{volumes "%0_up_light_on_ui" enable touch}
					{volumes "%0_up_laser_on_ui" enable touch}
					{volumes "body_s_up_%0" enable contact_ground contact obstacle blast bullet overlap}
					{bone show "upgrade_upper_%0"}
					{ani_play "%0_up_ui" 0.1}
					{tags add "ui"}
					{delay 12
						{tags remove "ui"}
						{bone hide	"%0_up_ui"}
						{bone hide	"%0_up_light_on_ui"}
						{bone hide	"%0_up_laser_on_ui"}
						{volumes "%0_up_light_on_ui" disable touch}
						{volumes "%0_up_laser_on_ui" disable touch}
						{ani_play "%0_up_ui" -0.1}
					}
				}
			}
		}
	)
	("upgrade_up" args peq10)
	("upgrade_up" args peq15)
	("upgrade_up" args flashlight_sf)
	("upgrade_up" args laser1mw)
	("upgrade_up" args laser5mw)
	("upgrade_up" args tactical_laser)
	("upgrade_up" args tactical_laser2)
	("upgrade_up" args zenitco)
	("upgrade_up" args liner)
	("upgrade_up" args lasercylinder1)
	("upgrade_up" args lasercylinder3)
	("upgrade_up" args lasercylinder4)
}


;---------------------------------------------------end_up






{"detach_light_r"
	{on spawn
		{volumes "body_s_r_peq10" disable contact_ground contact obstacle blast bullet overlap}
		{volumes "body_s_r_peq15" disable contact_ground contact obstacle blast bullet overlap}
		{volumes "body_s_r_flashlight_sf" disable contact_ground contact obstacle blast bullet overlap}
		{tags add "detach_r"}
	}
	(define "upgrade"
		{on "detach_light_r_%0"
			{if tagged "attach_r_%0" 
				{delay 0.5
					{volumes "attach_r" enable touch select}
					{delay 0.1 
						{tex_mod "laser_r_off"}
						{tex_mod "light_r_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					
 
					{tags remove "laser_on_r_%0"}
					{tags remove "light_on_r_%0"}
					{ani_play "caps_laser_r" -0.2}
					{ani_play "caps_front_r" -0.2}
					{start_sound "weapon/detach/"}
					{tags add "detach_r"}
					{tags remove "attach_r_%0"}
					{tags remove "light_on_r"}
					{tags remove "laser_on_r"}
					{tags remove "light_on_r_%0"}
					{tags remove "laser_on_r_%0"}
					{tags remove "attach_r"}
					{view stop	"fx_light_set_r_%0"}
					{view hide	"fx_light_set_r_%0"}
					{view stop	"fx_laser_set_r_%0"}
					{view hide	"fx_laser_set_r_%0"}
					{bone hide "upgrade_right_%0"}
					{volumes "body_s_r_%0" disable contact_ground contact obstacle blast bullet overlap}
					{spawn "%0" "upgrade_right_%0" {impulse up 0.1}}
				}
			}
		}
	)
	("upgrade" args peq10)
	("upgrade" args peq15)
	("upgrade" args flashlight_sf)
	("upgrade" args laser1mw)
	("upgrade" args laser5mw)
	("upgrade" args tactical_laser)
	("upgrade" args tactical_laser2)
	("upgrade" args zenitco)
	("upgrade" args liner)
	("upgrade" args lasercylinder1)
	("upgrade" args lasercylinder3)
	("upgrade" args lasercylinder4)
}
{"attach_light_r"
	{on spawn
		(define "spawn_upgrade_r"
			{volumes "%0_r_light_on_ui" disable contact_ground contact obstacle blast bullet overlap}
			{volumes "%0_r_laser_on_ui" disable contact_ground contact obstacle blast bullet overlap}
			{if not tagged "attach_r" 
				{bone hide	"upgrade_right_%0"}
			}
		)
		("spawn_upgrade_r" args peq10)
		("spawn_upgrade_r" args peq15)
		("spawn_upgrade_r" args flashlight_sf)
		("spawn_upgrade_r" args laser1mw)
		("spawn_upgrade_r" args laser5mw)
		("spawn_upgrade_r" args tactical_laser)
		("spawn_upgrade_r" args tactical_laser2)
		("spawn_upgrade_r" args zenitco)
		("spawn_upgrade_r" args liner)
		("spawn_upgrade_r" args lasercylinder1)
		("spawn_upgrade_r" args lasercylinder3)
		("spawn_upgrade_r" args lasercylinder4)
	}
	(define "upgrade"
		{on "attach_light_r_%0"
			{if tagged "detach_r" 
				{delay 0.5
					{volumes "attach_r" disable touch select}
					{start_sound "weapon/attach/"}
					{tags remove "detach_r"}
					{tags add "attach_r_%0"}
					{tags add "attach_r"}
					{bone show	"%0_r_ui"}
					{bone show	"%0_r_light_on_ui"}
					{bone show	"%0_r_laser_on_ui"}
					{volumes "%0_r_light_on_ui" enable touch}
					{volumes "%0_r_laser_on_ui" enable touch}
					{volumes "body_s_r_%0" enable contact_ground contact obstacle blast bullet overlap}
					{bone show "upgrade_right_%0"}
					{ani_play "%0_r_ui" 0.1}
					{tags add "ui"}
					{delay 12
						{tags remove "ui"}
						{bone hide	"%0_r_ui"}
						{bone hide	"%0_r_light_on_ui"}
						{bone hide	"%0_r_laser_on_ui"}
						{volumes "%0_r_light_on_ui" disable touch}
						{volumes "%0_r_laser_on_ui" disable touch}
						{ani_play "%0_r_ui" -0.1}
					}
				}
			}
		}
	)
	("upgrade" args peq10)
	("upgrade" args peq15)
	("upgrade" args flashlight_sf)
	("upgrade" args laser1mw)
	("upgrade" args laser5mw)
	("upgrade" args tactical_laser)
	("upgrade" args tactical_laser2)
	("upgrade" args zenitco)
	("upgrade" args liner)
	("upgrade" args lasercylinder1)
	("upgrade" args lasercylinder3)
	("upgrade" args lasercylinder4)
}

{"detach_light_l"
	{on spawn
		{volumes "body_s_l_peq10" disable contact_ground contact obstacle blast bullet overlap}
		{volumes "body_s_l_peq15" disable contact_ground contact obstacle blast bullet overlap}
		{volumes "body_s_l_flashlight_sf" disable contact_ground contact obstacle blast bullet overlap}
		{tags add "detach_l"}
	}
	(define "upgrade"
		{on "detach_light_l_%0"
			{if tagged "attach_l_%0" 
				{delay 0.5
					{volumes "attach_l" enable touch select}
					{delay 0.1 
						{tex_mod "laser_l_off"}
						{tex_mod "light_l_off"}
					}
					("check_tex" skin(1) )					
					("check_tex" skin(2) )					
					("check_tex" skin(3) )					
					("check_tex" skin(4) )					
					("check_tex" skin(5) )					
					("check_tex" skin(6) )					
					("check_tex" skin(7) )					
					("check_tex" skin(8) )					
					("check_tex" skin(9) )					
					("check_tex" skin(10) )					
					("check_tex" skin(d) )					
					("check_tex" skin(w) )					
					("check_tex" skin(s) )					 
					{tags remove "laser_on_l_%0"}
					{tags remove "light_on_l_%0"}
					{ani_play "caps_laser_l" -0.2}
					{ani_play "caps_front_l" -0.2}
					{start_sound "weapon/detach/"}
					{tags add "detach_l"}
					{tags remove "attach_l_%0"}
					{tags remove "light_on_l"}
					{tags remove "laser_on_l"}
					{tags remove "attach_l"}
					{view hide	"fx_light_set_l_%0"}
					{view stop	"fx_light_set_l_%0"}
					{view hide	"fx_laser_set_l_%0"}
					{view stop	"fx_laser_set_l_%0"}
					{bone hide "upgrade_left_%0"}
					{volumes "body_s_l_%0" disable contact_ground contact obstacle blast bullet overlap}
					{spawn "%0" "upgrade_left_%0" {impulse up 0.1}}
				}
			}
		}
	)
	("upgrade" args peq10)
	("upgrade" args peq15)
	("upgrade" args flashlight_sf)
	("upgrade" args laser1mw)
	("upgrade" args laser5mw)
	("upgrade" args tactical_laser)
	("upgrade" args tactical_laser2)
	("upgrade" args zenitco)
	("upgrade" args liner)
	("upgrade" args lasercylinder1)
	("upgrade" args lasercylinder3)
	("upgrade" args lasercylinder4)
}
{"attach_light_l"
	{on spawn
		(define "spawn_upgrade_l"
			{volumes "%0_l_light_on_ui" disable contact_ground contact obstacle blast bullet overlap}
			{volumes "%0_l_laser_on_ui" disable contact_ground contact obstacle blast bullet overlap}
			{if not tagged "attach_l" 
				{bone hide	"upgrade_left_%0"}
			}
		)
		("spawn_upgrade_l" args peq10)
		("spawn_upgrade_l" args peq15)
		("spawn_upgrade_l" args flashlight_sf)
		("spawn_upgrade_l" args laser1mw)
		("spawn_upgrade_l" args laser5mw)
		("spawn_upgrade_l" args tactical_laser)
		("spawn_upgrade_l" args tactical_laser2)
		("spawn_upgrade_l" args zenitco)
		("spawn_upgrade_l" args liner)
		("spawn_upgrade_l" args lasercylinder1)
		("spawn_upgrade_l" args lasercylinder3)
		("spawn_upgrade_l" args lasercylinder4)
	}
	(define "upgrade"
		{on "attach_light_l_%0"
			{if tagged "detach_l" 
				{delay 0.5
					{volumes "attach_l" disable touch select}
					{volumes "%0_l_light_on_ui" enable touch}
					{volumes "%0_l_laser_on_ui" enable touch}
					{bone show	"%0_l_ui"}
					{bone show	"%0_l_light_on_ui"}
					{bone show	"%0_l_laser_on_ui"}
					{start_sound "weapon/attach/"}
					{tags remove "detach_l"}
					{tags add "attach_l_%0"}
					{tags add "attach_l"}
					{volumes "body_s_l_%0" enable contact_ground contact obstacle blast bullet overlap}
					{bone show "upgrade_left_%0"}
					{ani_play "%0_l_ui" 0.1}
					{tags add "ui"}
					{delay 12
						{tags remove "ui"}
						{bone hide	"%0_l_ui"}
						{bone hide	"%0_l_light_on_ui"}
						{bone hide	"%0_l_laser_on_ui"}
						{volumes "%0_l_light_on_ui" disable touch}
						{volumes "%0_l_laser_on_ui" disable touch}
						{ani_play "%0_l_ui" -0.1}
					}
				}
			}
		}
	)
	("upgrade" args peq10)
	("upgrade" args peq15)
	("upgrade" args flashlight_sf)
	("upgrade" args laser1mw)
	("upgrade" args laser5mw)
	("upgrade" args tactical_laser)
	("upgrade" args tactical_laser2)
	("upgrade" args zenitco)
	("upgrade" args liner)
	("upgrade" args lasercylinder1)
	("upgrade" args lasercylinder3)
	("upgrade" args lasercylinder4)
}



{"detach_light_d"
	{on spawn
		;{bone hide "upgrade_left_peq15"}
		;{bone hide "upgrade_left_sf"}
		{tags add "detach_d"}
	}
	(define "upgrade"
		{on "detach_light_d_%0"
			{if tagged "attach_d_%0" 
				{delay 0.5
					{volumes "attach_d" enable touch select}
					{tags remove "laser_on_d_%0"}
					{tags remove "light_on_d_%0"}
					{start_sound "weapon/detach/"}
					{tags add "detach_d"}
					{tags remove "attach_d_%0"}
					{tags remove "light_on_d"}
					{tags remove "laser_on_d"}
					{tags remove "attach_d"}
					{view hide	"fx_light_set_d_%0"}
					{view stop	"fx_light_set_d_%0"}
					{view hide	"fx_laser_set_d_%0"}
					{view stop	"fx_laser_set_d_%0"}
					{bone hide "upgrade_down_%0"}
					{volumes "body_s_d_%0" disable contact_ground contact obstacle blast bullet overlap}
					{spawn "%0" "upgrade_down_%0" {impulse up 0.1}}
				}
			}
		}
	)
	("upgrade" args zenitco)
	("upgrade" args tactical_laser)
	("upgrade" args tlr2)
	("upgrade" args sfx300)
	;("upgrade" args 3)
	;("upgrade" args 4)
}
{"attach_light_d"
	{on spawn
		;{tags add "attach_d"}
	}
	(define "upgrade"
		{on "attach_light_d_%0"
			{if tagged "detach_d" 
				{delay 0.5
					{volumes "attach_d" disable touch select}
					{start_sound "weapon/attach/"}
					{tags remove "detach_d"}
					{tags add "attach_d_%0"}
					{tags add "attach_d"}
					{volumes "body_s_d_%0" enable contact_ground contact obstacle blast bullet overlap}
					{bone show "upgrade_down_%0"}
				}
			}
		}
	)
	("upgrade" args zenitco)
	("upgrade" args tactical_laser)
	("upgrade" args tlr2)
	("upgrade" args sfx300)
	;("upgrade" args 3)
	;("upgrade" args 4)
}


{"detach_main"
	{on spawn
		;{tags add "detach_m"}
	}
	(define "upgrade"
		{on "detach_upgrade_%0"
			{if tagged "attach_m" 
				{delay 0.5
					{tags remove "view_%0"}
					{start_sound "weapon/detach/"}
					{tags remove "attach_m"}
					{tags add "detach_m"}
					{bone hide "upgrade_%0"}
					{bone hide "fx_main_%0"}
					{bone show "downgrade_%0"}
					{bone show "fx_main"}
					{spawn "suppressor_%0" "%0"}
				}
			}
		}
	)
	("upgrade" args tirant)
	;("upgrade" args 4)
}
{"attach_main"
	{on spawn
		;{tags add "attach_m"}
	}
	(define "upgrade"
		{on "attach_upgrade_%0"
			{if tagged "detach_m" 
				{delay 0.5
					{tags add "view_%0"}
					{start_sound "weapon/attach/"}
					{tags remove "detach_m"}
					{tags add "attach_m"}
					{bone hide "downgrade_%0"}
					{bone show "upgrade_%0"}
				}
			}
		}
	)
	("upgrade" args tirant)
	;("upgrade" args 4)
}
{"upgrade_set"
	{on spawn
		;{if not linked
		;	{impulse up 0.1}
		;}
		;{tags add "attach_m"}
	}
	{on "undermine"
		{delete}
	}
}
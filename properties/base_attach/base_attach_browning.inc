{bone "link_left_upgrade"
	{parameters "Voxels=0;"}
	{Matrix34
		0	0.00659432	0.999978
		-0.00658057	-0.999957	0.00659418
		0.999978	-0.00658044	4.28578e-05
		1.15407	-0.931955	0.00845361
	}
	{bone "upgrade_left_flashlight_sf"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.00576298	0.113704	-0.04128
		}
		{bone "fx_light_set_l_flashlight_sf"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				0.00435273	1.17177	0.526558
			}
		}
		{bone "flashlight_sf_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				-0.138775	-1.55859	1.64282
			}
			{bone "flashlight_sf_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.42425	1.91485	-0.0734341
				}
				{VolumeView "flashlight_sf_l_ui.ply"}
				{bone "flashlight_sf_l_light_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00156346	0.00695801	-0.00266075
					}
					{VolumeView "flashlight_sf_l_light_on_ui.ply"}
				}
			}
		}
		{bone "flashlight_sf_l"
			{parameters "CommonMesh;"}
			{Matrix34
				-1	0	0
				0	1	0
				0	0	-1
				0.000483067	0	-7.93934e-05
			}
			{visibility 0}
			{LODView
				{VolumeView "flashlight_sf_l.ply"}
				{VolumeView "flashlight_sf_l_lod1.ply"}
				{VolumeView "flashlight_sf_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_peq10"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.000710852	-0.179748	-0.063122
		}
		{bone "fx_laser_set_l_peq10"
			{Matrix34
				-0.000180081	1	0
				0.00018032	0	-1
				-1	-0.00018009	-0.00018032
				-0.189585	0.983141	0.392148
			}
		}
		{bone "an_peq10_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				-0.00516294	-0.217705	0.108795
			}
			{visibility 0}
			{LODView
				{VolumeView "an_peq10_l.ply"}
				{VolumeView "an_peq10_l_lod1.ply"}
				{VolumeView "an_peq10_l_lod2.ply"}
			}
			{bone "caps_front_l"
				{parameters "CommonMesh;"}
				{Matrix34
					-0.087157	0.996195	-5.83519e-05
					0.996195	0.0871569	-5.77847e-05
					-5.24791e-05	-6.31667e-05	-1
					0.291265	0.997031	-0.00450093
				}
				{visibility 0}
				{VolumeView "caps_front_l.ply"}
			}
		}
		{bone "peq10_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				0.119554	-1.76514	1.29341
			}
			{bone "peq10_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.18663	2.0016	-0.0767598
				}
				{VolumeView "peq10_l_ui.ply"}
				{bone "peq10_l_light_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0.00571888	0.999984	0
						1	0	0
						0.00163338	-0.00214577	-0.0122774
					}
					{VolumeView "peq10_l_light_on_ui.ply"}
				}
				{bone "peq10_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0.00571888	0.999984	0
						1	0	0
						0.00162141	-0.0123119	-0.0122797
					}
					{VolumeView "peq10_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "fx_light_set_l_peq10"
			{Matrix34
				-0.000180081	1	0
				0.00018032	0	-1
				-1	-0.00018009	-0.00018032
				0.20313	0.983141	0.414777
			}
		}
	}
	{bone "upgrade_left_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.0382437	0.0592852	-0.0363002
		}
		{bone "fx_light_set_l_peq15"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.371357	1.24264	0.263605
			}
		}
		{bone "fx_laser_set_l_peq15"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				0.326747	1.00145	0.236036
			}
		}
		{bone "caps_light_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0.984808	0.173648
				0	0.173648	-0.984808
				-1	0	0
				-0.318351	0.88184	0.315392
			}
			{visibility 0}
			{VolumeView "caps_light_l.ply"}
		}
		{bone "caps_laser_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				-1	0	0
				0	-1	0
				0.295526	0.758236	0.314766
			}
			{visibility 0}
			{VolumeView "caps_laser_l.ply"}
		}
		{bone "peq15_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				-0.00583041	-2.01209	1.49804
			}
			{bone "peq15_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.20169	1.86915	-0.0716805
				}
				{VolumeView "peq15_l_ui.ply"}
				{bone "peq15_l_light_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00152459	0.00674248	-0.00387263
					}
					{VolumeView "peq15_l_light_on_ui.ply"}
				}
				{bone "peq15_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00151297	0.00648689	-0.00387263
					}
					{VolumeView "peq15_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "peq15_l"
			{parameters "CommonMesh;"}
			{Position 8.57674e-05	-0.0282574	-0.0279045}
			{visibility 0}
			{LODView
				{VolumeView "peq15_l.ply"}
				{VolumeView "peq15_l_lod1.ply"}
				{VolumeView "peq15_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_lasercylinder4"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.00547766	0.146422	-0.0418293
		}
		{bone "fx_laser_set_l_lasercylinder4"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				0.00364116	0.824121	0.309068
			}
		}
		{bone "lasercylinder4_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	-1	0
				1	0	0
				-0.276842	2.00049	1.6812
			}
			{bone "lasercylinder4_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.47097	1.97766	-0.0758428
				}
				{VolumeView "lasercylinder4_l_ui.ply"}
				{bone "lasercylinder4_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161475	0.00718594	-0.00274825
					}
					{VolumeView "lasercylinder4_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "laser_rail_l_lasercylinder4"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.0297857	-0.0533795	0.0493417
			}
			{visibility 0}
			{LODView
				{VolumeView "laser_rail_l_lasercylinder4.ply"}
				{VolumeView "laser_rail_l_lasercylinder4_lod1.ply"}
				{VolumeView "laser_rail_l_lasercylinder4_lod2.ply"}
			}
			{bone "lasercylinder4_l"
				{parameters "CommonMesh;"}
				{Position 0.269053	-0.25775	-0.0324291}
				{visibility 0}
				{LODView
					{VolumeView "lasercylinder4_l.ply"}
					{VolumeView "lasercylinder4_l_lod1.ply"}
					{VolumeView "lasercylinder4_l_lod2.ply"}
				}
			}
		}
	}
	{bone "upgrade_left_lasercylinder3"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.00511744	0.151587	-0.0408823
		}
		{bone "fx_laser_set_l_lasercylinder3"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				0.00364116	0.719615	0.309068
			}
		}
		{bone "lasercylinder3_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	-1	0
				1	0	0
				-0.276842	2.08069	1.7213
			}
			{bone "lasercylinder3_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.47097	1.97766	-0.0758429
				}
				{VolumeView "lasercylinder3_l_ui.ply"}
				{bone "lasercylinder3_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161475	0.00718641	-0.00274849
					}
					{VolumeView "lasercylinder3_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "laser_rail_l_lasercylinder3"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.0290675	-0.0533791	0.0480614
			}
			{visibility 0}
			{LODView
				{VolumeView "laser_rail_l_lasercylinder3.ply"}
				{VolumeView "laser_rail_l_lasercylinder3_lod1.ply"}
				{VolumeView "laser_rail_l_lasercylinder3_lod2.ply"}
			}
			{bone "lasercylinder3_l"
				{parameters "CommonMesh;"}
				{Position 0.240784	-0.260505	-0.0279096}
				{visibility 0}
				{LODView
					{VolumeView "lasercylinder3_l.ply"}
					{VolumeView "lasercylinder3_l_lod1.ply"}
					{VolumeView "lasercylinder3_l_lod2.ply"}
				}
			}
		}
	}
	{bone "upgrade_left_liner"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.0100476	0.034606	-0.0385513
		}
		{bone "fx_laser_set_l_liner"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.000594079	1.31045	0.350914
			}
		}
		{bone "liner_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0.0085513	-5.427e-05	-0.999963
				-0.000553971	-1	4.95035e-05
				0.999963	-0.000553527	0.00855134
				-0.0349335	2.153	1.6966
			}
			{bone "liner_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.40309	1.8864	-0.0723432
				}
				{VolumeView "liner_l_ui.ply"}
				{bone "liner_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00154026	0.00685453	-0.00262141
					}
					{VolumeView "liner_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "liner_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				-0.00759818	0.256792	-0.0218282
			}
			{visibility 0}
			{LODView
				{VolumeView "liner_l.ply"}
				{VolumeView "liner_l_lod1.ply"}
				{VolumeView "liner_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_lasercylinder1"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.00887604	0.169688	-0.041177
		}
		{bone "fx_laser_set_l_lasercylinder1"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				0.00997537	1.11228	0.303502
			}
		}
		{bone "lasercylinder1_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	-1	0
				1	0	0
				-0.276842	2.07065	1.73132
			}
			{bone "lasercylinder1_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.47097	1.97766	-0.0758429
				}
				{VolumeView "lasercylinder1_l_ui.ply"}
				{bone "lasercylinder1_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161475	0.00718594	-0.00274825
					}
					{VolumeView "lasercylinder1_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "laser_rail_l_lasercylinder1"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.0290675	-0.0533791	0.0458372
			}
			{visibility 0}
			{LODView
				{VolumeView "laser_rail_l_lasercylinder1.ply"}
				{VolumeView "laser_rail_l_lasercylinder1_lod1.ply"}
				{VolumeView "laser_rail_l_lasercylinder1_lod2.ply"}
			}
			{bone "lasercylinder1_l"
				{parameters "CommonMesh;"}
				{Position 0.248965	-0.26019	-0.0366947}
				{visibility 0}
				{LODView
					{VolumeView "lasercylinder1_l.ply"}
					{VolumeView "lasercylinder1_l_lod1.ply"}
					{VolumeView "lasercylinder1_l_lod2.ply"}
				}
			}
		}
	}
	{bone "upgrade_left_tactical_laser"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.0108008	0.223103	-0.0340707
		}
		{bone "fx_laser_set_l_tactical_laser"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.158483	0.112591	0.326951
			}
		}
		{bone "tactical_laser_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				-0.212566	-2.11104	1.8087
			}
			{bone "tactical_laser_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.47097	1.97766	-0.0758428
				}
				{VolumeView "tactical_laser_l_ui.ply"}
				{bone "tactical_laser_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161475	0.00718641	-0.00274801
					}
					{VolumeView "tactical_laser_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "tactical_laser_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	0
				1	0	0
				0	0	-1
				-0.00160338	-0.284636	0.126612
			}
			{visibility 0}
			{LODView
				{VolumeView "tactical_laser_l.ply"}
				{VolumeView "tactical_laser_l_lod1.ply"}
				{VolumeView "tactical_laser_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_tactical_laser2"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.0095965	0.220114	-0.0410652
		}
		{bone "fx_laser_set_l_tactical_laser2"
			{parameters "Voxels=0;"}
			{Matrix34
				0	1	0
				0	0	-1
				-1	0	0
				-0.296795	0.748279	0.133301
			}
		}
		{bone "tactical_laser2_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				-0.0260062	-2.03966	1.77717
			}
			{bone "tactical_laser2_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.47097	1.97766	-0.0758428
				}
				{VolumeView "tactical_laser2_l_ui.ply"}
				{bone "tactical_laser2_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161476	0.00718641	-0.00274801
					}
					{VolumeView "tactical_laser2_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "tactical_laser2_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	0
				-1	0	0
				0	0	1
				0.0190625	-0.732914	0.102411
			}
			{visibility 0}
			{LODView
				{VolumeView "tactical_laser2_l.ply"}
				{VolumeView "tactical_laser2_l_lod1.ply"}
				{VolumeView "tactical_laser2_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_zenitco"
		{parameters "Voxels=0;"}
		{Position -0.0150855	-0.235616	-0.0572829}
		{bone "fx_laser_set_l_zenitco"
			{Matrix34
				-0.000180086	1	0
				0.00018032	0	-1
				-1	-0.000180096	-0.00018032
				-0.239848	0.906075	0.237677
			}
		}
		{bone "zenitco_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				0.246084	-1.33732	1.34032
			}
			{bone "zenitco_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					0.989063	1.66835	-0.0639799
				}
				{VolumeView "zenitco_l_ui.ply"}
				{bone "zenitco_l_light_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00135987	0.0737762	-0.145116
					}
					{VolumeView "zenitco_l_light_on_ui.ply"}
				}
				{bone "zenitco_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00135851	-0.108982	-0.145116
					}
					{VolumeView "zenitco_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "fx_light_set_l_zenitco"
			{Matrix34
				-0.000180086	1	0
				0.00018032	0	-1
				-1	-0.000180096	-0.00018032
				0.00202448	0.891879	0.589134
			}
		}
		{bone "zenitco_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				-0.0267773	0.201079	0.462308
			}
			{visibility 0}
			{LODView
				{VolumeView "zenitco_l.ply"}
				{VolumeView "zenitco_l_lod1.ply"}
				{VolumeView "zenitco_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_laser5mw"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.0080521	-0.329236	-0.0343368
		}
		{bone "fx_laser_set_l_laser5mw"
			{Matrix34
				0.000316417	1	0
				-1	0.000314943	-0.000311371
				-0.000311378	0	1
				-0.0803687	0.996741	0.221162
			}
		}
		{bone "laser5mw_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				0.099575	-1.62841	1.60921
			}
			{bone "laser5mw_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.17243	1.97766	-0.07584
				}
				{VolumeView "laser5mw_l_ui.ply"}
				{bone "laser5mw_l_light_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161205	0.0874543	-0.17202
					}
					{VolumeView "laser5mw_l_light_on_ui.ply"}
				}
				{bone "laser5mw_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161027	-0.129186	-0.17202
					}
					{VolumeView "laser5mw_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "fx_light_set_l_laser5mw"
			{Matrix34
				0.000316417	1	0
				-1	0.000314943	-0.000311371
				-0.000311378	0	1
				0.0232037	1.01783	0.370652
			}
		}
		{bone "laser5mw_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	-0.000678396
				1	0	0
				0	-0.000678404	-1
				0.000645181	0.285407	0.119651
			}
			{visibility 0}
			{LODView
				{VolumeView "laser5mw_l.ply"}
				{VolumeView "laser5mw_l_lod1.ply"}
				{VolumeView "laser5mw_l_lod2.ply"}
			}
		}
	}
	{bone "upgrade_left_laser1mw"
		{parameters "Voxels=0;"}
		{Matrix34
			1	0	0
			0	1	0
			0	0	1
			-0.0123657	-0.21735	-0.037323
		}
		{bone "fx_laser_set_l_laser1mw"
			{Matrix34
				0.000316417	1	0
				-1	0.000314943	-0.000311371
				-0.000311378	0	1
				0.00245562	0.569086	0.766014
			}
		}
		{bone "laser1mw_l_ui_bone"
			{parameters "Voxels=0;"}
			{Matrix34
				0	0	-1
				0	1	0
				1	0	0
				0.0583583	-1.61234	1.61885
			}
			{bone "laser1mw_l_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	1
					0	1	0
					-1	0	0
					1.17243	1.97766	-0.07584
				}
				{VolumeView "laser1mw_l_ui.ply"}
				{bone "laser1mw_l_light_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161205	0.0874543	-0.172019
					}
					{VolumeView "laser1mw_l_light_on_ui.ply"}
				}
				{bone "laser1mw_l_laser_on_ui"
					{parameters "CommonMesh;"}
					{Matrix34
						0	0	-1
						0	1	0
						1	0	0
						0.00161027	-0.129186	-0.17202
					}
					{VolumeView "laser1mw_l_laser_on_ui.ply"}
				}
			}
		}
		{bone "fx_light_set_l_laser1mw"
			{Matrix34
				0.000316417	1	0
				-1	0.000314943	-0.000311371
				-0.000311378	0	1
				0.00204986	1.35367	0.390831
			}
		}
		{bone "laser_1mw_l"
			{parameters "CommonMesh;"}
			{Matrix34
				0	1	0
				1	0	0
				0	0	-1
				0.00415377	0.0617075	0.12429
			}
			{visibility 0}
			{LODView
				{VolumeView "laser_1mw_l.ply"}
				{VolumeView "laser_1mw_l_lod1.ply"}
				{VolumeView "laser_1mw_l_lod2.ply"}
			}
		}
	}
}
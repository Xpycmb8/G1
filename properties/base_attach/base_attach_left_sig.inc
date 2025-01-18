{bone "upgrade_right_zenitco"
	{parameters "Voxels=0;"}
	{Position -0.00860322	-0.209908	-0.0154791}
	{bone "fx_laser_set_r_zenitco"
		{Matrix34
			-0.00018008	1	0
			0.00018032	0	-1
			-1	-0.000180106	-0.00018032
			-0.251451	0.944153	0.249174
		}
	}
	{bone "zenitco_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.1131	1.76447	0.657999
		}
		{bone "zenitco_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.03691	1.74906	-0.067075
			}
			{VolumeView "zenitco_r_ui.ply"}
			{bone "zenitco_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00142574	0.0773454	-0.152136
				}
				{VolumeView "zenitco_r_light_on_ui.ply"}
			}
			{bone "zenitco_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00142419	-0.114254	-0.152136
				}
				{VolumeView "zenitco_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_zenitco"
		{Matrix34
			-0.00018008	1	0
			0.00018032	0	-1
			-1	-0.000180106	-0.00018032
			0.0021224	0.898716	0.617633
		}
	}
	{bone "zenitco_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0280726	0.210806	0.484672
		}
		{visibility 0}
		{LODView
			{VolumeView "zenitco_r.ply"}
			{VolumeView "zenitco_r_lod1.ply"}
			{VolumeView "zenitco_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_tactical_laser2"
	{parameters "Voxels=0;"}
	{Position -0.00584424	0.288957	-0.00386339}
	{bone "fx_laser_set_r_tactical_laser2"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.311153	0.784477	0.13975
		}
	}
	{bone "tactical_laser2_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.64854	2.12664	0.305031
		}
		{bone "tactical_laser2_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.54213	2.07333	-0.0795119
			}
			{VolumeView "tactical_laser2_r_ui.ply"}
			{bone "tactical_laser2_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00169283	0.00753403	-0.00288105
				}
				{VolumeView "tactical_laser2_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser2_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.0199847	-0.768369	0.107365
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser2_r.ply"}
			{VolumeView "tactical_laser2_r_lod1.ply"}
			{VolumeView "tactical_laser2_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_tactical_laser"
	{parameters "Voxels=0;"}
	{Position -0.00572586	0.233911	-0.00583279}
	{bone "fx_laser_set_r_tactical_laser"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.16615	0.118037	0.342767
		}
	}
	{bone "tactical_laser_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.64854	1.87351	0.686644
		}
		{bone "tactical_laser_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.54212	2.07333	-0.0795119
			}
			{VolumeView "tactical_laser_r_ui.ply"}
			{bone "tactical_laser_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00169289	0.00753403	-0.00288105
				}
				{VolumeView "tactical_laser_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			-0.00168073	-0.298406	0.132737
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser_r.ply"}
			{VolumeView "tactical_laser_r_lod1.ply"}
			{VolumeView "tactical_laser_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_peq15"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.046802	0.184333	-0.0011465
	}
	{bone "fx_light_set_r_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.404817	1.35461	0.287356
		}
	}
	{bone "fx_laser_set_r_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.356188	1.09168	0.257303
		}
	}
	{bone "caps_light_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0.984808	0.173648
			0	0.173648	-0.984808
			-1	0	0
			-0.347035	0.961296	0.34381
		}
		{visibility 0}
		{VolumeView "caps_light_r.ply"}
	}
	{bone "caps_laser_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	1
			-1	0	0
			0	-1	0
			0.322153	0.826556	0.343127
		}
		{visibility 0}
		{VolumeView "caps_laser_r.ply"}
	}
	{bone "peq15_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.38512	1.91108	0.430202
		}
		{bone "peq15_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.30996	2.03757	-0.0781391
			}
			{VolumeView "peq15_r_ui.ply"}
			{bone "peq15_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00166196	0.00734997	-0.00422144
				}
				{VolumeView "peq15_r_light_on_ui.ply"}
			}
			{bone "peq15_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00164932	0.0070715	-0.00422144
				}
				{VolumeView "peq15_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "peq15_r"
		{parameters "CommonMesh;"}
		{Position 0.00962138	-0.0192108	-0.030419}
		{visibility 0}
		{LODView
			{VolumeView "peq15_r.ply"}
			{VolumeView "peq15_r_lod1.ply"}
			{VolumeView "peq15_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_peq10"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00473249	-0.0749412	-0.00504786
	}
	{bone "an_peq10_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	1
			0	1	0
			-1	0	0
			0.00499594	-0.212981	0.0849007
		}
		{visibility 0}
		{LODView
			{VolumeView "an_peq10_r.ply"}
			{VolumeView "an_peq10_r_lod1.ply"}
			{VolumeView "an_peq10_r_lod2.ply"}
		}
		{bone "caps_front_r"
			{parameters "CommonMesh;"}
			{Matrix34
				0.0871559	0.996195	0
				-0.996195	0.0871559	0
				0	0	1
				0.284716	0.974613	-0.00440443
			}
			{visibility 0}
			{VolumeView "caps_front_r.ply"}
		}
	}
	{bone "fx_laser_set_r_peq10"
		{Matrix34
			0.000315678	1	0
			-1	0.000315682	-0.000311375
			-0.000311374	0	1
			-0.185322	0.961035	0.383331
		}
	}
	{bone "peq10_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.16738	1.74826	0.392338
		}
		{bone "peq10_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.15994	1.9566	-0.0750338
			}
			{VolumeView "peq10_r_ui.ply"}
			{bone "peq10_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00159478	0.0865226	-0.170188
				}
				{VolumeView "peq10_r_light_on_ui.ply"}
			}
			{bone "peq10_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00159323	-0.12781	-0.170188
				}
				{VolumeView "peq10_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_peq10"
		{Matrix34
			0.000315678	1	0
			-1	0.000315682	-0.000311375
			-0.000311374	0	1
			0.192994	0.961034	0.38333
		}
	}
}
{bone "upgrade_right_liner"
	{parameters "Voxels=0;"}
	{Position -0.000110626	0.0399117	0.00107676}
	{bone "fx_laser_set_r_liner"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0137459	1.37963	0.370491
		}
	}
	{bone "liner_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.61491	-2.14744	0.571568
		}
		{bone "liner_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.48044	1.9904	-0.0763314
			}
			{VolumeView "liner_r_ui.ply"}
			{bone "liner_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162518	0.00723267	-0.00276577
				}
				{VolumeView "liner_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "liner_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.00801718	0.270948	-0.0230314
		}
		{visibility 0}
		{LODView
			{VolumeView "liner_r.ply"}
			{VolumeView "liner_r_lod1.ply"}
			{VolumeView "liner_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_lasercylinder4"
	{parameters "Voxels=0;"}
	{Position -0.00416565	0.161317	-0.000103235}
	{bone "lasercylinder4_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.68219	-2.16966	0.39927
		}
		{bone "lasercylinder4_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.54213	2.07333	-0.0795118
			}
			{VolumeView "lasercylinder4_r_ui.ply"}
			{bone "lasercylinder4_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00169289	0.00753403	-0.00288105
				}
				{VolumeView "lasercylinder4_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_laser_set_r_lasercylinder4"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.0026437	0.870605	0.32482
		}
	}
	{bone "laser_rail_r_lasercylinder4"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0288873	-0.0559611	0.0502473
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder4.ply"}
			{VolumeView "laser_rail_r_lasercylinder4_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder4_lod2.ply"}
		}
		{bone "lasercylinder4_r"
			{parameters "CommonMesh;"}
			{Position 0.28207	-0.278693	-0.0261157}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder4_r.ply"}
				{VolumeView "lasercylinder4_r_lod1.ply"}
				{VolumeView "lasercylinder4_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_lasercylinder3"
	{parameters "Voxels=0;"}
	{Position -0.0052681	0.166865	-0.00377589}
	{bone "fx_laser_set_r_lasercylinder3"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.0026437	0.761043	0.32482
		}
	}
	{bone "lasercylinder3_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.68219	-2.16966	0.39927
		}
		{bone "lasercylinder3_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.54213	2.07333	-0.0795119
			}
			{VolumeView "lasercylinder3_r_ui.ply"}
			{bone "lasercylinder3_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00169289	0.00753403	-0.00288105
				}
				{VolumeView "lasercylinder3_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_r_lasercylinder3"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0293297	-0.0559621	0.0523454
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder3.ply"}
			{VolumeView "laser_rail_r_lasercylinder3_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder3_lod2.ply"}
		}
		{bone "lasercylinder3_r"
			{parameters "CommonMesh;"}
			{Position 0.252432	-0.273107	-0.0292598}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder3_r.ply"}
				{VolumeView "lasercylinder3_r_lod1.ply"}
				{VolumeView "lasercylinder3_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_lasercylinder1"
	{parameters "Voxels=0;"}
	{Position -0.0052439	0.169322	-3.58224e-05}
	{bone "fx_laser_set_r_lasercylinder1"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00884414	1.16439	0.321335
		}
	}
	{bone "lasercylinder1_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.68219	-2.16966	0.39927
		}
		{bone "lasercylinder1_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.54213	2.07333	-0.0795118
			}
			{VolumeView "lasercylinder1_r_ui.ply"}
			{bone "lasercylinder1_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00169283	0.00753403	-0.00288105
				}
				{VolumeView "lasercylinder1_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_r_lasercylinder1"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0296745	-0.0559616	0.0486519
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder1.ply"}
			{VolumeView "laser_rail_r_lasercylinder1_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder1_lod2.ply"}
		}
		{bone "lasercylinder1_r"
			{parameters "CommonMesh;"}
			{Position 0.261008	-0.272776	-0.0384698}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder1_r.ply"}
				{VolumeView "lasercylinder1_r_lod1.ply"}
				{VolumeView "lasercylinder1_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_laser5mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0379508	-0.355736	0.00688165
	}
	{bone "fx_light_set_r_laser5mw"
		{Matrix34
			0.000315679	1	0
			-1	0.000315682	-0.000311375
			-0.000311374	0	1
			0.0243254	1.06706	0.388583
		}
	}
	{bone "fx_laser_set_r_laser5mw"
		{Matrix34
			0.000315679	1	0
			-1	0.000315682	-0.000311375
			-0.000311374	0	1
			-0.0842572	1.04496	0.231861
		}
	}
	{bone "laser5mw_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.2268	2.50663	0.430949
		}
		{bone "laser5mw_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.22915	2.07333	-0.0795105
			}
			{VolumeView "laser5mw_r_ui.ply"}
			{bone "laser5mw_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00168997	0.0916848	-0.180341
				}
				{VolumeView "laser5mw_r_light_on_ui.ply"}
			}
			{bone "laser5mw_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00168824	-0.135436	-0.180342
				}
				{VolumeView "laser5mw_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser5mw_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	-0.000678402
			1	0	0
			0	-0.000678398	-1
			0.0319173	0.299215	0.121082
		}
		{visibility 0}
		{LODView
			{VolumeView "laser5mw_r.ply"}
			{VolumeView "laser5mw_r_lod1.ply"}
			{VolumeView "laser5mw_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_laser1mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0023315	-0.279573	-0.000389576
	}
	{bone "fx_laser_set_r_laser1mw"
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.00244474	0.56665	0.762736
		}
	}
	{bone "laser1mw_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.2768	2.19436	0.393526
		}
		{bone "laser1mw_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.16741	1.96919	-0.0755169
			}
			{VolumeView "laser1mw_r_ui.ply"}
			{bone "laser1mw_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00160509	0.08708	-0.171284
				}
				{VolumeView "laser1mw_r_light_on_ui.ply"}
			}
			{bone "laser1mw_r_laser_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00160348	-0.128633	-0.171284
				}
				{VolumeView "laser1mw_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_laser1mw"
		{Matrix34
			0.000315679	1	0
			-1	0.000315681	-0.000311372
			-0.000311377	0	1
			0.00204003	1.34788	0.389159
		}
	}
	{bone "laser_1mw_r"
		{parameters "CommonMesh;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			0.00413597	0.0614443	0.123758
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_1mw_r.ply"}
			{VolumeView "laser_1mw_r_lod1.ply"}
			{VolumeView "laser_1mw_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_flashlight_sf"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0015794	0.259532	-0.00577974
	}
	{bone "fx_light_set_r_flashlight_sf"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00456202	1.22846	0.552029
		}
	}
	{bone "flashlight_sf_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.56626	2.14087	0.256979
		}
		{bone "flashlight_sf_r_ui"
			{parameters "CommonMesh;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.49314	1.80073	-0.076986
			}
			{VolumeView "flashlight_sf_r_ui.ply"}
			{bone "flashlight_sf_r_light_on_ui"
				{parameters "CommonMesh;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00163913	0.00729465	-0.00278962
				}
				{VolumeView "flashlight_sf_r_light_on_ui.ply"}
			}
		}
	}
	{bone "flashlight_sf_r"
		{parameters "CommonMesh;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	-1
			0	0	-0.000506759
		}
		{visibility 0}
		{LODView
			{VolumeView "flashlight_sf_r.ply"}
			{VolumeView "flashlight_sf_r_lod1.ply"}
			{VolumeView "flashlight_sf_r_lod2.ply"}
		}
	}
}

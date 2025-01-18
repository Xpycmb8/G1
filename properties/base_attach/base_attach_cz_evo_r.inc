{bone "upgrade_right_tactical_laser"
	{parameters "Voxels=0;"}
	{Position 0.00403512	0.28377	0.001737}
	{bone "fx_laser_set_r_tactical_laser"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.152144	0.108087	0.313873
		}
	}
	{bone "tactical_laser_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.50957	1.71558	0.628762
		}
		{bone "tactical_laser_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.41213	1.89855	-0.0728092
			}
			{VolumeView "tactical_laser_r_ui.ply"}
			{bone "tactical_laser_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015502	0.00689888	-0.00263834
				}
				{VolumeView "tactical_laser_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser_r"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			-0.00153923	-0.273251	0.121547
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser_r.ply"}
			{VolumeView "tactical_laser_r_lod1.ply"}
			{VolumeView "tactical_laser_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_zenitco"
	{parameters "Voxels=0;"}
	{Position -0.0046699	-0.10631	-0.0175267}
	{bone "fx_laser_set_r_zenitco"
		{Matrix34
			-0.000180079	1	0
			0.00018032	0	-1
			-1	-0.000180114	-0.00018032
			-0.241393	0.906387	0.239207
		}
	}
	{bone "zenitco_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.06858	1.69389	0.631679
		}
		{bone "zenitco_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				0.995432	1.6791	-0.064392
			}
			{VolumeView "zenitco_r_ui.ply"}
			{bone "zenitco_r_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00136864	0.0742517	-0.146051
				}
				{VolumeView "zenitco_r_light_on_ui.ply"}
			}
			{bone "zenitco_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00136727	-0.109683	-0.146051
				}
				{VolumeView "zenitco_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_zenitco"
		{Matrix34
			-0.000180079	1	0
			0.00018032	0	-1
			-1	-0.000180114	-0.00018032
			0.00203753	0.862767	0.592928
		}
	}
	{bone "zenitco_r"
		{parameters "ID=body;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.0269498	0.202374	0.465285
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
	{Position -0.00215161	0.28377	-0.000784695}
	{bone "fx_laser_set_r_tactical_laser2"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.292434	0.737283	0.131343
		}
	}
	{bone "tactical_laser2_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.54936	1.9987	0.286681
		}
		{bone "tactical_laser2_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.44935	1.9486	-0.0747284
			}
			{VolumeView "tactical_laser2_r_ui.ply"}
			{bone "tactical_laser2_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00159097	0.00708055	-0.00270772
				}
				{VolumeView "tactical_laser2_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "tactical_laser2_r"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			-1	0	0
			0	0	1
			0.0187824	-0.722144	0.100906
		}
		{visibility 0}
		{LODView
			{VolumeView "tactical_laser2_r.ply"}
			{VolumeView "tactical_laser2_r_lod1.ply"}
			{VolumeView "tactical_laser2_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_laser1mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.00292981	-0.105749	0.00491402
	}
	{bone "fx_laser_set_r_laser1mw"
		{Matrix34
			0.000315677	1	0
			-1	0.000315678	-0.000311374
			-0.000311375	0	1
			0.00231421	0.536422	0.722047
		}
	}
	{bone "laser1mw_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.20869	2.0773	0.372533
		}
		{bone "laser1mw_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.10514	1.86414	-0.0714884
			}
			{VolumeView "laser1mw_r_ui.ply"}
			{bone "laser1mw_r_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00151944	0.0824342	-0.162146
				}
				{VolumeView "laser1mw_r_light_on_ui.ply"}
			}
			{bone "laser1mw_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00151795	-0.121771	-0.162146
				}
				{VolumeView "laser1mw_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_laser1mw"
		{Matrix34
			0.000315677	1	0
			-1	0.000315678	-0.000311374
			-0.000311375	0	1
			0.00193107	1.27598	0.368398
		}
	}
	{bone "laser_1mw_r"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			1	0	0
			0	0	-1
			0.00391519	0.058166	0.117156
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_1mw_r.ply"}
			{VolumeView "laser_1mw_r_lod1.ply"}
			{VolumeView "laser_1mw_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_laser5mw"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0319805	-0.105586	0.00962517
	}
	{bone "laser5mw_r"
		{parameters "ID=body;"}
		{Matrix34
			0	1	-0.0006784
			1	0	0
			0	-0.0006784	-1
			0.0306407	0.287246	0.116239
		}
		{visibility 0}
		{LODView
			{VolumeView "laser5mw_r.ply"}
			{VolumeView "laser5mw_r_lod1.ply"}
			{VolumeView "laser5mw_r_lod2.ply"}
		}
	}
	{bone "fx_light_set_r_laser5mw"
		{Matrix34
			0.000315678	1	0
			-1	0.000315683	-0.000311375
			-0.000311374	0	1
			0.0233524	1.02438	0.373039
		}
	}
	{bone "fx_laser_set_r_laser5mw"
		{Matrix34
			0.000315678	1	0
			-1	0.000315683	-0.000311375
			-0.000311374	0	1
			-0.0808871	1.00316	0.222586
		}
	}
	{bone "laser5mw_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.17772	2.40637	0.413711
		}
		{bone "laser5mw_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.17998	1.99039	-0.07633
			}
			{VolumeView "laser5mw_r_ui.ply"}
			{bone "laser5mw_r_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162238	0.088017	-0.173128
				}
				{VolumeView "laser5mw_r_light_on_ui.ply"}
			}
			{bone "laser5mw_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00162077	-0.130018	-0.173128
				}
				{VolumeView "laser5mw_r_laser_on_ui.ply"}
			}
		}
	}
}
{bone "upgrade_right_lasercylinder4"
	{parameters "Voxels=0;"}
	{Position -0.000500917	0.28377	0.00281286}
	{bone "lasercylinder4_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.54039	-1.98677	0.365613
		}
		{bone "lasercylinder4_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.41213	1.89855	-0.0728092
			}
			{VolumeView "lasercylinder4_r_ui.ply"}
			{bone "lasercylinder4_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015502	0.00689888	-0.0026381
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
			0.00242078	0.797215	0.297438
		}
	}
	{bone "laser_rail_r_lasercylinder4"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0264522	-0.0512438	0.0460116
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder4.ply"}
			{VolumeView "laser_rail_r_lasercylinder4_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder4_lod2.ply"}
		}
		{bone "lasercylinder4_r"
			{parameters "ID=body;"}
			{Position 0.258292	-0.2552	-0.0239141}
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
	{bone "fx_laser_set_r_lasercylinder3"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00244331	0.70338	0.300209
		}
	}
	{bone "lasercylinder3_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.55474	-2.00527	0.369018
		}
		{bone "lasercylinder3_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.42528	1.91624	-0.0734873
			}
			{VolumeView "lasercylinder3_r_ui.ply"}
			{bone "lasercylinder3_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00156456	0.00696278	-0.00266278
				}
				{VolumeView "lasercylinder3_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_r_lasercylinder3"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0271076	-0.051722	0.0483793
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder3.ply"}
			{VolumeView "laser_rail_r_lasercylinder3_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder3_lod2.ply"}
		}
		{bone "lasercylinder3_r"
			{parameters "ID=body;"}
			{Position 0.233305	-0.252414	-0.0270427}
			{visibility 0}
			{VolumeView "lasercylinder3_r.ply"}
		}
	}
}
{bone "upgrade_right_lasercylinder1"
	{parameters "Voxels=0;"}
	{Position 0.000841498	0.28377	0.00527117}
	{bone "fx_laser_set_r_lasercylinder1"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.0080986	1.06623	0.294248
		}
	}
	{bone "lasercylinder1_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.54039	-1.98677	0.365613
		}
		{bone "lasercylinder1_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.41213	1.89855	-0.0728092
			}
			{VolumeView "lasercylinder1_r_ui.ply"}
			{bone "lasercylinder1_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015502	0.00689888	-0.0026381
				}
				{VolumeView "lasercylinder1_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "laser_rail_r_lasercylinder1"
		{parameters "ID=body;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.027173	-0.0512443	0.0445507
		}
		{visibility 0}
		{LODView
			{VolumeView "laser_rail_r_lasercylinder1.ply"}
			{VolumeView "laser_rail_r_lasercylinder1_lod1.ply"}
			{VolumeView "laser_rail_r_lasercylinder1_lod2.ply"}
		}
		{bone "lasercylinder1_r"
			{parameters "ID=body;"}
			{Position 0.239006	-0.249782	-0.0352267}
			{visibility 0}
			{LODView
				{VolumeView "lasercylinder1_r.ply"}
				{VolumeView "lasercylinder1_r_lod1.ply"}
				{VolumeView "lasercylinder1_r_lod2.ply"}
			}
		}
	}
}
{bone "upgrade_right_liner"
	{parameters "Voxels=0;"}
	{Position 0.0035193	0.28377	0.0105219}
	{bone "fx_laser_set_r_liner"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.0126446	1.26912	0.340814
		}
	}
	{bone "liner_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	1
			1.48555	-1.97542	0.525784
		}
		{bone "liner_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.36186	1.83096	-0.0702171
			}
			{VolumeView "liner_r_ui.ply"}
			{bone "liner_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.001495	0.00665331	-0.00254416
				}
				{VolumeView "liner_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "liner_r"
		{parameters "ID=body;"}
		{Matrix34
			0	0	-1
			0	1	0
			1	0	0
			-0.00737476	0.249245	-0.0211865
		}
		{visibility 0}
		{LODView
			{VolumeView "liner_r.ply"}
			{VolumeView "liner_r_lod1.ply"}
			{VolumeView "liner_r_lod2.ply"}
		}
	}
}
{bone "upgrade_right_peq15"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0343311	-0.018301	0.0107414
	}
	{bone "peq15_r"
		{parameters "ID=body;"}
		{Position 0.00897419	-0.0179186	-0.0283728}
		{visibility 0}
		{LODView
			{VolumeView "peq15_r.ply"}
			{VolumeView "peq15_r_lod1.ply"}
			{VolumeView "peq15_r_lod2.ply"}
		}
	}
	{bone "fx_light_set_r_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			-0.377587	1.26349	0.268027
		}
	}
	{bone "fx_laser_set_r_peq15"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.332229	1.01825	0.239996
		}
	}
	{bone "caps_light_r"
		{parameters "ID=body;"}
		{Matrix34
			0	0.984808	0.173648
			0	0.173648	-0.984808
			-1	0	0
			-0.323692	0.896635	0.320684
		}
		{VolumeView "caps_light_r.ply"}
	}
	{bone "caps_laser_r"
		{parameters "ID=body;"}
		{Matrix34
			0	0	1
			-1	0	0
			0	-1	0
			0.300484	0.770957	0.320046
		}
		{VolumeView "caps_laser_r.ply"}
	}
	{bone "peq15_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.29195	1.78254	0.401264
		}
		{bone "peq15_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.22185	1.90051	-0.0728831
			}
			{VolumeView "peq15_r_ui.ply"}
			{bone "peq15_r_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015502	0.00685549	-0.0039376
				}
				{VolumeView "peq15_r_light_on_ui.ply"}
			}
			{bone "peq15_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.0015384	0.00659561	-0.0039376
				}
				{VolumeView "peq15_r_laser_on_ui.ply"}
			}
		}
	}
}
{bone "upgrade_right_peq10"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	1	0
		0	0	1
		-0.0198944	-0.163564	0.000259489
	}
	{bone "an_peq10_r"
		{parameters "ID=body;"}
		{Matrix34
			0	0	1
			0	1	0
			-1	0	0
			0.00500774	-0.21348	0.0850995
		}
		{visibility 0}
		{LODView
			{VolumeView "an_peq10_r.ply"}
			{VolumeView "an_peq10_r_lod1.ply"}
			{VolumeView "an_peq10_r_lod2.ply"}
		}
		{bone "caps_front_r"
			{parameters "ID=body;"}
			{Matrix34
				0.0871559	0.996195	0
				-0.996195	0.0871559	0
				0	0	1
				0.285383	0.976895	-0.0044148
			}
			{VolumeView "caps_front_r.ply"}
		}
	}
	{bone "fx_laser_set_r_peq10"
		{Matrix34
			0.000315674	1	0
			-1	0.00031568	-0.000311375
			-0.000311375	0	1
			-0.185756	0.963286	0.384229
		}
	}
	{bone "peq10_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.17011	1.75235	0.393258
		}
		{bone "peq10_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.16266	1.96118	-0.0752097
			}
			{VolumeView "peq10_r_ui.ply"}
			{bone "peq10_r_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00159854	0.0867252	-0.170587
				}
				{VolumeView "peq10_r_light_on_ui.ply"}
			}
			{bone "peq10_r_laser_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00159693	-0.12811	-0.170587
				}
				{VolumeView "peq10_r_laser_on_ui.ply"}
			}
		}
	}
	{bone "fx_light_set_r_peq10"
		{Matrix34
			0.000315674	1	0
			-1	0.00031568	-0.000311375
			-0.000311375	0	1
			0.193446	0.963285	0.384228
		}
	}
}
{bone "upgrade_right_flashlight_sf"
	{parameters "Voxels=0;"}
	{Matrix34
		1	0	0
		0	0.999989	0.00475796
		0	-0.00475795	0.999989
		0.00420427	0.279008	-0.000775129
	}
	{bone "flashlight_sf_r"
		{parameters "ID=body;"}
		{Matrix34
			-1	0	0
			0	1	0
			0	0	-1
			0	0	-0.000486463
		}
		{visibility 0}
		{LODView
			{VolumeView "flashlight_sf_r.ply"}
			{VolumeView "flashlight_sf_r_lod1.ply"}
			{VolumeView "flashlight_sf_r_lod2.ply"}
		}
	}
	{bone "fx_light_set_r_flashlight_sf"
		{parameters "Voxels=0;"}
		{Matrix34
			0	1	0
			0	0	-1
			-1	0	0
			0.00437951	1.17932	0.529948
		}
	}
	{bone "flashlight_sf_r_ui_bone"
		{parameters "Voxels=0;"}
		{Matrix34
			-1	0	0
			0	-1	0
			0	0	1
			1.50361	2.05523	0.2467
		}
		{bone "flashlight_sf_r_ui"
			{parameters "ID=body;"}
			{Matrix34
				0	0	1
				0	1	0
				-1	0	0
				1.43342	1.7287	-0.0739065
			}
			{VolumeView "flashlight_sf_r_ui.ply"}
			{bone "flashlight_sf_r_light_on_ui"
				{parameters "ID=body;"}
				{Matrix34
					0	0	-1
					0	1	0
					1	0	0
					0.00157356	0.00700235	-0.00267804
				}
				{VolumeView "flashlight_sf_r_light_on_ui.ply"}
			}
		}
	}
}
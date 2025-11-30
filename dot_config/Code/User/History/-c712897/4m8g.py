import open3d as o3d

# Load point cloud
pcd = o3d.io.read_point_cloud("/home/david/Uni/Text-to-3D/video-22-11-2025-7/C2video-Anubis/pts.ply")

# Optional: downsample to reduce size but keep detail
# pcd = pcd.voxel_down_sample(voxel_size=0.02)

# Optional: remove noise but keep most points
cl, ind = pcd.remove_statistical_outlier(nb_neighbors=20, std_ratio=0.5)
pcd_clean = pcd.select_by_index(ind)

# save point cloud
o3d.io.write_point_cloud("/home/david/Uni/Text-to-3D/video-23-11-2025-1 (2)/CS2_Train/pts_clean.ply", pcd_clean)


# Visualize the cleaned point cloud (no mesh involved)
o3d.visualization.draw_geometries([pcd_clean])


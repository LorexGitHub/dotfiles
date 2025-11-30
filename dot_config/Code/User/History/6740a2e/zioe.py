import open3d as o3d

def visualize_pcd(path) :
    pcd = o3d.io.read_point_cloud(path)
    o3d.visualization.draw_geometries([pcd])


def visualize_mesh(path) :
    mesh = o3d.io.read_triangle_mesh(path)
    o3d.visualization.draw_geometries([mesh], mesh_show_back_face = True)

# image-16-11-2025-10
# visualize_pcd("/home/david/Uni/Text-to-3D/image-16-11-2025-10/pts.ply")
# visualize_pcd("/home/david/Uni/Text-to-3D/image-16-11-2025-10/pts_clean.ply")
# visualize_mesh(/home/david/Uni/Text-to-3D/image-16-11-2025-10/mesh.ply)

# image-16-11-2025-11
# visualize_pcd("/home/david/Uni/Text-to-3D/image-16-11-2025-11/pts.ply")
# visualize_pcd("/home/david/Uni/Text-to-3D/image-16-11-2025-11/pts_clean.ply")
# visualize_mesh(/home/david/Uni/Text-to-3D/image-16-11-2025-11/mesh.ply)

# video-22-11-2025-7
# visualize_pcd("/home/david/Uni/Text-to-3D/video-22-11-2025-7/C2video-Anubis/pts.ply")
# visualize_pcd("/home/david/Uni/Text-to-3D/video-22-11-2025-7/C2video-Anubis/pts_clean.ply")
# visualize_mesh("/home/david/Uni/Text-to-3D/video-22-11-2025-7/C2video-Anubis/mesh.ply")

# video-23-11-2025-1
# visualize_pcd("/home/david/Uni/Text-to-3D/video-23-11-2025-1/pts.ply")
# visualize_pcd("/home/david/Uni/Text-to-3D/video-23-11-2025-1/pts_clean.ply")
# visualize_mesh("/home/david/Uni/Text-to-3D/video-23-11-2025-1/mesh.ply")

visualize_pcd("/home/david/Uni/Text-to-3D/video-22-11-2025-7/C2video-Anubis/pts.ply")
#visualize_mesh("/home/david/Uni/Text-to-3D/video-22-11-2025-7/C2video-Anubis/mesh.ply")
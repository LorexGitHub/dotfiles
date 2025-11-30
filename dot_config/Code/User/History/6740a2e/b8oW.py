impot open3d as o3d

void visualize-pcd(String path) {
    pcd = o3d.io.read_point_cloud(path)
    o3d.visualization.draw_geometries([pcd])
}


void visualize-mesh(String path) {
    mesh = o3d.io.read_triangle_mesh(path)
    o3d.visualization.draw_geometries([mesh])
}

visualize-pcd("/home/david/Uni/Text-to-3D/image-16-11-2025-11/pts.ply")
#visualize-mesh("/home/david/Uni/Text-to-3D/image-16-11-2025-11/mesh.ply")
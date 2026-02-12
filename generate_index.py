import os

# Configuración: Nombre de carpeta -> Título y Descripción para su README interno
CATEGORY_INFO = {
    "Advanced_Algorithms_Graphs": {
        "title": "🕸️ Advanced Algorithms & Graph Theory",
        "desc": "Solutions focused on **Graph Traversal** (BFS, DFS), **Shortest Paths** (Dijkstra), and complex recursion. These problems typically require $O(V+E)$ or $O(n \log n)$ complexity."
    },
    "Data_Structures_Map_Set": {
        "title": "📦 Data Structures (STL)",
        "desc": "Implementation of efficient data storage using **C++ STL Containers** like `std::map`, `std::set`, `std::priority_queue`, and custom structs."
    },
    "Exams_and_Extras": {
        "title": "🎓 Exams & Special Challenges",
        "desc": "Problems from **FIB Lab Exams** (Control sets starting with X) and miscellaneous challenges covering mixed topics."
    },
    "General_Programming": {
        "title": "💻 General Programming Fundamentals",
        "desc": "Foundational exercises focusing on **Iterative Logic**, **Vectors**, **Matrices**, and basic modular design (PRO1 level)."
    }
}

def get_lang_details(folder_name):
    if folder_name.endswith("_en"): return "🇬🇧 EN"
    elif folder_name.endswith("_es"): return "🇪🇸 ES"
    elif folder_name.endswith("_ca"): return "🟡🔴 CA"
    return "🏳️ N/A"

def generate_readmes():
    for folder, info in CATEGORY_INFO.items():
        if not os.path.exists(folder):
            print(f"⚠️ La carpeta {folder} no existe, saltando...")
            continue

        print(f"🔨 Generando README para: {folder}...")
        
        lines = []
        # Cabecera del README específico
        lines.append(f"# {info['title']}")
        lines.append(f"{info['desc']}")
        lines.append("")
        lines.append("## 📋 Problem List")
        lines.append("| ID | Language | Solution Code | Jutge Statement |")
        lines.append("|:--:|:----:|:-------------:|:---------------:|")

        # Listar problemas dentro de esta carpeta
        problems = sorted([p for p in os.listdir(folder) if os.path.isdir(os.path.join(folder, p))])

        for p_folder in problems:
            # Datos para la tabla
            clean_id = p_folder.split('_')[0]
            lang_display = get_lang_details(p_folder)
            
            # Enlaces (ahora son relativos a la carpeta actual)
            local_url = f"./{p_folder}"  # Apunta a la subcarpeta del problema
            jutge_url = f"https://jutge.org/problems/{p_folder}"
            
            row = f"| **{clean_id}** | {lang_display} | [View Code]({local_url}) | [Official Link ↗]({jutge_url}) |"
            lines.append(row)
        
        lines.append("")
        lines.append("---")
        lines.append("*Auto-generated index.*")

        # Escribir el README.md DENTRO de la carpeta
        readme_path = os.path.join(folder, "README.md")
        with open(readme_path, "w", encoding="utf-8") as f:
            f.write("\n".join(lines))
            
    print("\n✅ ¡Listo! Se han creado 4 archivos README.md dentro de las subcarpetas.")

if __name__ == "__main__":
    generate_readmes()
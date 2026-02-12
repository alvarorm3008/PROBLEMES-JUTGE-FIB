import os
import re

# 1. Configuración de Categorías Principales y sus Subtipos (Keywords)
CONFIG = {
    "Advanced_Algorithms_Graphs": {
        "title": "🕸️ Advanced Algorithms & Graph Theory",
        "desc": "Deep dive into graph algorithms and complexity analysis.",
        "subtypes": {
            "Shortest Paths (Dijkstra/Bellman)": ["dijkstra", "bellman", "weight", "cost", "distance"],
            "Topological Sort & Dependencies": ["topological", "dependency", "precedence"],
            "Tree Algorithms": ["tree", "forest", "leaf", "root"],
            "Graph Traversal (BFS/DFS)": ["bfs", "dfs", "visited", "adj", "graph"], # Fallback general
            "Recursion & Backtracking": ["backtrack", "solution", "recursive"]
        }
    },
    "Data_Structures_Map_Set": {
        "title": "📦 Data Structures (STL)",
        "desc": "Efficient data manipulation using C++ Standard Template Library.",
        "subtypes": {
            "Priority Queues (Heaps)": ["priority_queue", "heap", "greater"],
            "Maps & Dictionaries": ["map<", "unordered_map", "key", "value"],
            "Sets & Unique Elements": ["set<", "unordered_set", "unique"],
            "Stacks & Queues": ["stack<", "queue<", "push", "pop"]
        }
    },
    "General_Programming": {
        "title": "💻 General Programming Fundamentals",
        "desc": "Foundational logic, loops, and array manipulation.",
        "subtypes": {
            "Matrices & 2D Vectors": ["vector<vector", "matrix", "row", "col"],
            "Searching & Sorting": ["binary_search", "sort", "merge", "lower_bound"],
            "Iterative Logic & Math": ["while", "for", "cin", "cout"]
        }
    },
    "Exams_and_Extras": {
        "title": "🎓 Exams & Special Challenges",
        "desc": "Real exam questions and mixed challenges.",
        "subtypes": {
            "Lab Exams (X Codes)": ["X"], # Detectamos por nombre de carpeta
            "Miscellaneous": []
        }
    }
}

def get_file_content(folder_path):
    """Busca el archivo .cc y devuelve su contenido."""
    try:
        for f in os.listdir(folder_path):
            if f.endswith(".cc") or f.endswith(".cpp"):
                with open(os.path.join(folder_path, f), 'r', errors='ignore') as file:
                    return file.read().lower()
    except:
        return ""
    return ""

def determine_subtype(folder_name, content, category_key):
    """Decide el subtipo basándose en keywords o nombre."""
    subtypes = CONFIG[category_key]["subtypes"]
    
    # Caso especial para Exámenes (miramos el nombre de carpeta)
    if category_key == "Exams_and_Extras":
        if folder_name.startswith("X"):
            return "Lab Exams (X Codes)"
        return "Miscellaneous"

    # Para los demás, miramos el contenido del código
    for subtype, keywords in subtypes.items():
        for kw in keywords:
            if kw in content:
                return subtype
    
    return "Other / Uncategorized"

def get_lang_details(folder_name):
    if folder_name.endswith("_en"): return "🇬🇧 EN"
    elif folder_name.endswith("_es"): return "🇪🇸 ES"
    elif folder_name.endswith("_ca"): return "🟡🔴 CA"
    return "🏳️ N/A"

def generate_smart_readmes():
    for folder, info in CONFIG.items():
        if not os.path.exists(folder):
            continue
            
        print(f"🧠 Analizando carpeta: {folder}...")
        
        # Estructura para agrupar: { "Subtipo": [lista de problemas] }
        grouped_problems = {k: [] for k in info["subtypes"].keys()}
        grouped_problems["Other / Uncategorized"] = []

        # Leer carpetas de problemas
        problems = sorted([p for p in os.listdir(folder) if os.path.isdir(os.path.join(folder, p))])

        for p in problems:
            content = get_file_content(os.path.join(folder, p))
            subtype = determine_subtype(p, content, folder)
            grouped_problems[subtype].append(p)

        # Generar Markdown
        lines = []
        lines.append(f"# {info['title']}")
        lines.append(f"{info['desc']}")
        lines.append("")
        
        # Iterar por subtipos y crear tablas
        for subtype, p_list in grouped_problems.items():
            if not p_list: continue # Si no hay problemas en este subtipo, saltar
            
            lines.append(f"## {subtype}")
            lines.append("| ID | Language | Solution | Jutge Link |")
            lines.append("|:--:|:----:|:--------:|:----------:|")
            
            for p in p_list:
                clean_id = p.split('_')[0]
                lang = get_lang_details(p)
                local = f"./{p}"
                jutge = f"https://jutge.org/problems/{p}"
                lines.append(f"| **{clean_id}** | {lang} | [View Code]({local}) | [Official ↗]({jutge}) |")
            
            lines.append("") # Espacio tras la tabla

        lines.append("---")
        lines.append(f"*Auto-generated via Python script based on code analysis.*")

        # Guardar README
        with open(os.path.join(folder, "README.md"), "w", encoding="utf-8") as f:
            f.write("\n".join(lines))

    print("✅ ¡Hecho! Los READMEs internos ahora están divididos por temáticas.")

if __name__ == "__main__":
    generate_smart_readmes()
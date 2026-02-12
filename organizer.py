import os
import shutil
#
# Definim les carpetes de destí
CATEGORIES = {
    "Advanced_Algorithms_Graphs": [],
    "Data_Structures_Map_Set": [],
    "Exams_and_Extras": [],
    "General_Programming": []
}

# Paraules clau per detectar el tipus de problema mirant el codi .cc
KEYWORDS_GRAPH = ["adj", "vis", "dfs", "bfs", "dijkstra", "topological", "priority_queue"]
KEYWORDS_STRUCTS = ["map<", "set<", "stack<", "struct Node"]

def get_category(folder_name):
    # 1. Si comença per X, va directe a Extres
    if folder_name.startswith("X"):
        return "Exams_and_Extras"
    
    # 2. Mirem a dins del fitxer .cc per veure de què va
    try:
        files = os.listdir(folder_name)
        cc_file = next((f for f in files if f.endswith('.cc') or f.endswith('.cpp')), None)
        
        if cc_file:
            with open(os.path.join(folder_name, cc_file), 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read().lower()
                
                # Busquem patrons de grafs o algorismes avançats
                if any(k in content for k in KEYWORDS_GRAPH):
                    return "Advanced_Algorithms_Graphs"
                
                # Busquem estructures de dades (Maps, Sets)
                if any(k in content for k in KEYWORDS_STRUCTS):
                    return "Data_Structures_Map_Set"
    except Exception as e:
        print(f"Error llegint {folder_name}: {e}")

    # 3. Si no trobem res especial, és programació general
    return "General_Programming"

def organize():
    # Creem les carpetes si no existeixen
    for cat in CATEGORIES:
        if not os.path.exists(cat):
            os.makedirs(cat)
            print(f"Created directory: {cat}")

    # Itere sobre totes les carpetes del directori actual
    for item in os.listdir():
        # Ignorem l'script mateix, el README, la carpeta .git i les carpetes de destí
        if item in CATEGORIES or item.startswith('.') or not os.path.isdir(item) or item == "__pycache__":
            continue
            
        # Decidim on va
        category = get_category(item)
        
        # Movem la carpeta
        src_path = item
        dst_path = os.path.join(category, item)
        
        print(f"Moving {item} -> {category}...")
        try:
            shutil.move(src_path, dst_path)
        except Exception as e:
            print(f"Error moving {item}: {e}")

if __name__ == "__main__":
    confirm = input("Això mourà les carpetes Pxxxx i Xxxxx a subcarpetes organitzades. Continuar? (y/n): ")
    if confirm.lower() == 'y':
        organize()
        print("✅ Organització completada!")
    else:
        print("Operació cancel·lada.")
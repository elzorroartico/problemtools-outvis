import sys
def check_image_type() -> bool: #Checks the file type and returns bool 
    permitted_filetypes = [
        b'\x89PNG\r\n\x1a\n',  # PNG file header
        b'\xff\xd8\xff\xe0\x10\x00JF',     # JPEG and jpg file header
        ]

    file = sys.argv[1]
    if file.endswith(".svg"):
        try:
                with open(file, 'r', encoding='utf-8') as f:
                    content = f.read(256)          #Reads the XML declaration and first 500 characters. Then checks if the declaration is correct and if the <svg> tag is present
                if content.startswith('<?xml') and '<svg' in content:
                    print(content)
                    print("IS LARGE SVG")
                    return 
        except Exception as e:
            print(f"Error checking SVG: {e}")
    else:
        with open(file, "rb") as f:
            file_signature = f.read(8)
            print(file_signature)
    return

if __name__ == '__main__':  
    check_image_type()

def read_and_convert_xpm3_to_xpm42(file_path):
    try:
        # Read the original XPM file
        with open(file_path, 'r') as file:
            lines = file.readlines()

        # Prepare the XPM42 file content
        xpm42 = ["!XPM42"]
        # Assuming the header is on the fourth line
        header_info = lines[3].strip('",').strip().split()
        xpm42.append(' '.join(header_info))

        # Process color definitions and pixel data
        color_count = int(header_info[2])
        start_pixel_data = 4 + color_count + 1  # Start after the header and color definitions

        # Adding color definitions
        for i in range(4, start_pixel_data):
            color_line = lines[i].strip('",').strip()
            xpm42.append(color_line)

        # Adding pixel data
        for i in range(start_pixel_data, len(lines)):
            pixel_line = lines[i].strip('",').strip()
            if pixel_line:  # Avoid adding empty lines
                xpm42.append(pixel_line)

        # Write the converted content to a new XPM42 file
        new_file_path = file_path.replace('.xpm', '_xpm42.xpm')
        with open(new_file_path, 'w') as file:
            for line in xpm42:
                file.write(line + '\n')

        print("Conversion complete! The new file is saved as: {}".format(new_file_path))

    except Exception as e:
        print("An error occurred: {}".format(e))

# Replace 'your_xpm_file.xpm' with the path to your XPM file
read_and_convert_xpm3_to_xpm42('platingnormal3.xpm')


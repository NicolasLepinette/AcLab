class FileData:
    def __init__(self, file_path):
        input_file = open(file_path, "r")
        content = [line.split() for line in input_file]
        input_file.close

        for x in range(len(content)):
            for y in range(len(content[x])):
                content[x][y] = int(content[x][y])

        self.size = (content[0][0], content[0][1])
        self.weights = content[1:self.size[0]+1]
        self.routes = []
        self.queries = []

        isQuery = False
        for route in content[self.size[0]+1:]:
            if route == [0, 0, 0, 0]:
                isQuery = True
                continue
            if not isQuery:
                self.routes.append(route)
            else:
                self.queries.append(route)
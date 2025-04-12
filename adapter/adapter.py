class InternalClass:
    def fetch(self):
        return "get user info"

class ExternalClass:
    def search(self):
        return "get user info"

class Adapter:
    def __init__(self, external):
        self.external = external
    
    def fetch(self):
        return self.external.search()

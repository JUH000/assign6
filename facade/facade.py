class CPU:
    def process(self):
        return "CPU 처리 중"

class Memory:
    def load(self):
        return "메모리 로딩 중"

class SSD:
    def read(self):
        return "SSD 드라이브 읽는 중"

class Computer: # 파사드 클래스
    def __init__(self):
        self.cpu = CPU()
        self.memory = Memory()
        self.ssd = SSD()
    
    def boot(self):
        self.ssd.read()
        self.memory.load()
        self.cpu.process()


c = Computer()
c.boot()

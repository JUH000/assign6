// 내부 인터페이스 (클라이언트가 기대하는 인터페이스)
interface InternalClass {
    fun fetch(): String
}

// 외부 클래스 (인터페이스가 다름)
class ExternalClass {
    fun search(): String {
        return "get user info"
    }
}

// 어댑터 클래스
class Adapter(private val external: ExternalClass) : InternalClass {
    override fun fetch(): String {
        return external.search()
    }
}

fun main() {
    val external = ExternalClass()
    val adapter: InternalClass = Adapter(external)

    println(adapter.fetch())  // "get user info"
}

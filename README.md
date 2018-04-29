# ANSI_Color_Enabler
## 상세 설명

C언어는 프로그램에서 WinAPI를 사용해 글자색을 표현할 수 있습니다. <br>
그런데 Java에서는 콘솔에 글자색을 직접적으로 표현할 수가 없어, ANSI escape sequence를 사용해 간접적으로 표현합니다.

ANSI Color를 Unix, Linux에서는 기본적으로 지원하나 Windows에서는 지원하지 않습니다. <br>
따라서 JANSI나 JCDP같은 서드파티 코드를 추가해야 윈도에서 사용할 수 있었습니다. <br>
그러나 드디어, Windows10에서 약간의 설정으로 ANSI Color가 기본 지원하게 되었어요.

이 프로그램은 위의 '약간의 설정'을 해주는 것으로 레지스트리에 DWORD값 1개를 추가합니다. <br>
만약, 추가한 후 cmd나 PowerShell에서 적용이 안된다면 컴퓨터를 재부팅 해주세요.

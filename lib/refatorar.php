<?php

$substituicoes = [
    "define" => "defina",
    "include" => "inclua",
    "include_next" => "inclua_próximo",
    "ifdef" => "se_definido",
    "ifndef" => "se_não_definido",
    "elif" => "senão_se",
    "endif" => "fim_se",
    "defined" => "definido",
    "undef" => "não_definido",
    "error" => "erro",
    "warning" => "aviso",
    "line" => "linha",
    "pragma" => "diretiva",

    "int" => "inteiro",
    "void" => "vazio",
    "char" => "caractere",
    "if" => "se",
    "else" => "senão",
    "while" => "enquanto",
    "break" => "pare",
    "return" => "retorne",
    "for" => "para",
    "extern" => "externo",
    "static" => "estático",
    "unsigned" => "sem_sinal",
    "goto" => "ir_para",
    "do" => "faça",
    "continue" => "continue",
    "switch" => "troque",
    "case" => "caso",

    "const" => "constante",
    "volatile" => "volátil",
    "long" => "longo",
    "register" => "registrador",
    "signed" => "sinalizado",
    "auto" => "automático",
    "inline" => "em_linha",
    "restrict" => "restrito",

    "_Generic" => "_Genérico",
    
    "float" => "real",
    "double" => "duplo",
    "_Bool" => "_Lógico",
    "short" => "curto",
    "struct" => "estrutura",
    "union" => "união",
    "typedef" => "defina_tipo",
    "default" => "padrão",
    "enum" => "enumeração",
    "sizeof" => "tamanho_de",
    "typeof" => "tipo_de",
    "asm" => "assembler",

    "__LINE__" => "__LINHA__",
    "__FILE__" => "__ARQUIVO__",
    "__DATE__" => "__DATA__",
    "__TIME__" => "__HORA__",
    "__FUNCTION__" => "__FUNÇÃO__",
    "__VA_ARGS__" => "__VARIÁVEIS_ARGS__",
    "__COUNTER__" => "__CONTADOR__",

    "__FUNC__" => "__função__",

    "__NAN__" => "__não_é_número__",
    "__SNAN__" => "__não_é_número_sinalizado__",
    "__INF__" => "__infinito__",

    "section" => "sessão",
    "aligned" => "alinhado",
    "packed" => "empacotado",
    "weak" => "fraco",
    "alias" => "pseudônimo",
    "unused" => "não_usado",
    "cdecl" => "declaração",
    "stdcall" => "chamada_convêncional",
    "fastcall" => "chamada_rápida",
    "regparm" => "parâmetro_registrador",
    
    "__mode__" => "__modo__",
    "__word__" => "__palavra__",
    
    "dllexport" => "exporte_dll",
    "dllimport" => "importe_dll",
    "noreturn" => "sem_retorno",
    "visibility" => "visibilidade",
];


function substituirPalavrasExatas($conteudo, $substituicoes) {
    foreach ($substituicoes as $original => $novo) {
        // Expressão para corresponder somente palavras exatas
        $padrao = '/\b' . preg_quote($original, '/') . '\b/';
        $conteudo = preg_replace($padrao, $novo, $conteudo);
    }
    return $conteudo;
}

// Função para varrer diretórios recursivamente
function obterArquivos($diretorio, $extensoes = ['c', 'h', 'S', 's']) {
    $arquivos = [];
    $iterador = new RecursiveIteratorIterator(new RecursiveDirectoryIterator($diretorio));
    foreach ($iterador as $arquivo) {
        if ($arquivo->isFile()) {
            $ext = pathinfo($arquivo->getFilename(), PATHINFO_EXTENSION);
            if (in_array(strtolower($ext), $extensoes)) {
                $arquivos[] = $arquivo->getPathname();
            }
        }
    }
    return $arquivos;
}

// Diretório base (atual)
$baseDir = __DIR__;
$arquivos = obterArquivos($baseDir);

foreach ($arquivos as $arquivo) {
    $conteudo = file_get_contents($arquivo);
    $novoConteudo = substituirPalavrasExatas($conteudo, $substituicoes);

    // Só sobrescreve se houver alterações
    if ($conteudo !== $novoConteudo) {
        file_put_contents($arquivo, $novoConteudo);
        echo "Refatorado: $arquivo\n";
    }
}
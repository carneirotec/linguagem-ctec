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
    "goto" => "vá_para",
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
    
    "float" => "real",
    "double" => "duplo",
    "_Bool" => "_Lógico",
    "short" => "curto",
    "struct" => "estrutura",
    "union" => "união",
    "typedef" => "defina_tipo",
    "default" => "padrão",
    "enum" => "enumeração",
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
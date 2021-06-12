//
//  EmojiMemoryGame.swift
//  Memorize-3
//
//  Created by Revanth_Avs on 18/05/21.
//

import SwiftUI

class EmojiMemoryGame: ObservableObject {
    @Published private var model: MemoryGame<String> = EmojiMemoryGame.createMemoryGame()
    
    static func createMemoryGame() -> MemoryGame<String> {
        let emojis = ["👻","🎃","👹","🕷","👾"]
        let random_number = Int.random(in: 3...5)
        return MemoryGame<String>(numberOfPairOfCards: random_number) { pairIndex in
            return emojis[pairIndex]
        }
    }
    
//        MemoryGame<String>(numberOfPairOfCards: 2){ _ in "😂" }
//        MemoryGame<String>(numberOfPairOfCards: 2, cardContentFactory: {(pairIndex: Int) -> String in
//            return "😂"
//        }) emojis.count
    
    // MARK: - Access to the Model
    
    var cards: Array<MemoryGame<String>.Card> {
        return model.cards
    }
    
    
    // MARK: - Intent(s)
    
    func choose(card: MemoryGame<String>.Card) {
        model.choose(card: card)
    }
}
